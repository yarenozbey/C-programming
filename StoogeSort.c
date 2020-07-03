#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
void stoogesort(int array[] , int left,int right)
{
    int tmp, k;
    if(array[left]>array[right]){
        tmp=array[left];
        array[left]=array[right];
        array[right]=tmp;
    }
    if((right-left)>1){
        k=(int)((right-left+1)/3);
        stoogesort(array,left, right-k);
        stoogesort(array, left+k, right);
        stoogesort(array, left, right-k);
   }
}

void create_array(int array[], int size)
{
    int i;
    for(i=0;i<size;i++)
        array[i]=rand()%size;
}




int main()
{
    clock_t start,end;
    double time[100];
    int i,j,N,n[100],X[100000];
    printf("Dizi sayisini giriniz: "); scanf("%d",&N);

    for(i=0;i<N;i++){
        printf("%d. dizinin eleman sayisini giriniz: ",i+1); scanf("%d",&n[i]);
        create_array(X,n[i]);
        start = clock();
        stoogesort(X,0,n[i]);
        end = clock();
        time[i] = (double)(end - start)/CLOCKS_PER_SEC;
        printf("\nGECEN SURE: %f sn\n\n",time[i]);
    }

    //bar diyagramýn boyutunu belirlemek icin en uzun sureyi buluyoruz
    double max = time[0];
    for(i=0;i<N;i++){
        if (time[i]>max){
            max = time[i];
        }
    }

    //bar diyagram yazdýrma
    for(i=max*100+2;i>0;i--){
            printf("\n");
            for(j=0;j<N;j++){
                if(time[j]*100+2<i){
                    printf(" \t\t");
                }
                else if(i==2){
                    printf("%d\t\t",n[j]);
                }
                else if(i==1){
                    printf("%f sn\t",time[j]);
                }
                else{
                    printf("*\t\t");
                }

            }

    }


    return 0;
}
