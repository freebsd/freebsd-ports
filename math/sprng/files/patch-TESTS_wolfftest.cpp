--- TESTS/wolfftest.cpp.orig	2009-06-13 21:46:10 UTC
+++ TESTS/wolfftest.cpp
@@ -14,7 +14,7 @@ using namespace std;
 
 /*#define PARALLEL*/
 
-int lattice_size, *spin, *stack, nsites;
+int lattice_size, *spin, *my_stack, nsites;
 Sprng **genptr;			/* array of random number generators */
 int exponent, mask; /* Used for efficiency purposes */
 double prob;
@@ -74,12 +74,12 @@ void Single_Cluster_Update(void) /* update lattice spi
 	if (genptr[i]->sprng() > prob)
 	  continue;
 	spin[nnJ]=-spin[nnJ];
-	stack[++Ipt]=nnJ;
+	my_stack[++Ipt]=nnJ;
       }
     
     if(Ipt>=0)
       {
-	i=stack[Ipt];
+	i=my_stack[Ipt];
 	Ipt--;
       }
     else i=-1;
@@ -217,8 +217,8 @@ void minitialize(int rng_type, int seed, int param, in
   
 
   spin = static_cast<int *>(malloc(nsites*sizeof(int)));
-  stack = static_cast<int *>(malloc(nsites*sizeof(int)));
-  if(!spin || !stack)
+  my_stack = static_cast<int *>(malloc(nsites*sizeof(int)));
+  if(!spin || !my_stack)
   {
     printf("\n\tMemory allocation failure, program exits!\n");
     exit(-1);
