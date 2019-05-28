#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// method2
void minimumBribes(int q_count, int* q) 
{
	int i = 0;
	int result = 0;

	for (i=(q_count-1); i>=0; i--)
	{
		if ( *(q+i) != (i+1))
		{
			if (((i-1) >= 0) && (*(q+i-1) == i+1))
			{
				 *(q+i-1) = *(q+i);
				 *(q+i) = i+1;

				 result++;
			}
			else if (((i-2) >= 0) && (*(q+i-2) == i+1))
			{
				 *(q+i-2) = *(q+i-1);
				 *(q+i-1) = *(q+i);
				 *(q+i) = i+1;

				 result += 2;
			}
			else 
			{
				// debug
				printf("Position: %d\n", i);

				printf("Too chaotic\n");
				return;
			}	

		}	
	}

	printf("%d\n", result);
}

int main()
{
	int n = 0;
	int* q = NULL;

	char str[1024];
	char* token = NULL;

	int i = 0;

	printf("Please enter the number of people in the queue: \n");
	scanf("%d", &n);
	printf("Please enter the final state of the queue: \n");
	scanf("\n");
	scanf("%[^\n]", str);

	q = malloc(n * sizeof(int));

	// split string
	token = strtok(str, " ");
	
	i = 0;

	while (token)
	{
		*(q + i) = atoi(token); 
		
		i++;

		token = strtok(NULL, " ");
	}

	minimumBribes(n, q);		

	return 0;
}

// method1
/*
void minimumBribes(int q_count, int* q) 
{
	int i = 0, j = 0;

	int tmp = 0;
	int result = 0;

	// check vaild
	for (i=0; i<q_count; i++)
	{
		// due to only bribe in front of them
		//if ((*(q+i) > i+1+2) || (*(q+i) < i+1-2))
		if (*(q+i) > i+1+2)
		{
			// debug
			//printf("Position: %d\n", i);

			printf("Too chaotic\n");
			return;
		} 	
	}
	
	// count the number		
	for (i=0; i<q_count-1; i++)
	{
		for (j=0; j<q_count-1-i; j++)
		{	
			if (*(q+j) > *(q+j+1))
			{
				// swap
				tmp = *(q+j); 
				*(q+j) = *(q+j+1);
				*(q+j+1) = tmp;

				// count
				result++;
			}
		}	
	}

	printf("%d\n", result);
}
*/