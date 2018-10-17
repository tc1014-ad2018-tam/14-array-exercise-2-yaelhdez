//Carlos Yael Hernandez Alcala
//A01412016
//A01412016@ITESM.MX


#include <stdio.h>
#include <ctype.h>

//---------------------------------------------------MENU FUNCTION------------------------------------------------------
void Menu(){
    printf("1. Array sum\n");            //only printf instructions
    printf("2. Array Average\n");
    printf("3. Array min\n");
    printf("4. Array max\n");
    printf("0. Exit\n");
    printf("Option: ");


}

//---------------------------------------------------SUM FUNCTION------------------------------------------------------
double Sum(double mynumbers[], unsigned int n) {
    double totalsum=0.0;

    for (int i = 0; i <n ; ++i) {
        totalsum+=mynumbers[i];   //This loop do the sum of the numbers
    }
    return totalsum; //This function returns the total sum
}
//---------------------------------------------------AVERAGE FUNCTION------------------------------------------------------
double Average(double sum, unsigned int n) {
    return sum/n; //This function returns the result of the operation

}

//---------------------------------------------------MIN FUNCTION------------------------------------------------------

double MinValue(double mynumbers[], unsigned int n, int *cell) {
    double min= mynumbers[0];
    *cell=0;

    for (int i = 1; i < n ; ++i) {
        if (mynumbers[i]<min){
            min=mynumbers[i];           //This loop select the min value of the numbers
            *cell= i;
        }

    }

    return min; //This function returns de min value.
}

//---------------------------------------------------MAX FUNCTION------------------------------------------------------

double MaxValue(double mynumbers[], unsigned int n, int *cell) {
    double max = mynumbers[0];
    *cell = 0;

    for (int i = 1; i < n; ++i) {
        if (mynumbers[i] > max) {
            max = mynumbers[i];     //This loop select the max value of the numbers
            *cell = i;
        }

    }

    return max; //This function returns de max value.
}

//---------------------------------------------------MAIN FUNCTION------------------------------------------------------
int main() {
    unsigned int n; //This variable will give a size to the array
    int option; //Variable option that we will use in the switch
    int cell;   //Variable cell
    double min; //Variable min
    double max; //Variable max

    printf("how many numbers do you want?\n");
    scanf("%d",&n); //variable size request

    double num[n]; //array with size n

    for (int i = 0; i <n ; ++i) { //this loop will request numbers to the user
        printf("gimme the element %i",i+1);
        scanf("%lf",&num[i]);
    }

    do{
        Menu(); //Function Menu(); call
        scanf("%d",&option);

        switch ((option)){
            case 1:
                Sum(num, n);
                printf("The sum is equals to %lf",Sum(num,n)); //sum(); function call
                break;
            case 2:
                printf("The average is equals to %lf",Average(Sum(num,n),n)); //average(); function call
                break;
            case 3:
                min=MinValue(num,n, &cell); //MinValue(); function call
                printf("The min value is %lf and its cell is %i",min,cell);
                break;
            case 4:
                max=MaxValue(num,n, &cell); //MaxValue(); function call
                printf("The max value is %lf and its cell is %i",max,cell);
                break;
            case 0:   //if the user wants to close the program, needs to enter this number
                printf("Bye");
                break;
            default:
                printf("invalid option."); //if the user enter an invalid option of the switch, the program will take this path
                break;
        }
        printf("\n\n"); // Space Jump
    }while (option!=0); //The loop continues if the user don't enter a 0

    return 0;
}
