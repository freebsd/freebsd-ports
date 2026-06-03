--- TESTS/mpitests/wolff.cpp.orig	2021-01-15 16:37:36 UTC
+++ TESTS/mpitests/wolff.cpp
@@ -13,7 +13,7 @@ using namespace std;
 
 /*#define PARALLEL*/
 
-int lattice_size, *spin, *stack, nsites;
+int lattice_size, *spin, *my_stack, nsites;
 Sprng **genptr; /* array of random number generators */
 int exponent, mask; /* Used for efficiency purposes */
 double prob;
@@ -80,12 +80,12 @@ void Single_Cluster_Update (void) /* update lattice sp
 	  if (genptr[i]->sprng () > prob)
 	    continue;
 	  spin[nnJ] = -spin[nnJ];
-	  stack[++Ipt] = nnJ;
+	  my_stack[++Ipt] = nnJ;
 	}
 
       if (Ipt >= 0)
 	{
-	  i = stack[Ipt];
+	  i = my_stack[Ipt];
 	  Ipt--;
 	}
       else
@@ -219,8 +219,8 @@ void minitialize (int rng_type, int seed, int param, i
       Energy[i][j] = Cv[i][j] = 0.0;
 
   spin = static_cast<int*> (malloc (nsites * sizeof(int)));
-  stack = static_cast<int*> (malloc (nsites * sizeof(int)));
-  if (!spin || !stack)
+  my_stack = static_cast<int*> (malloc (nsites * sizeof(int)));
+  if (!spin || !my_stack)
     {
       printf ("\n\tMemory allocation failure, program exits!\n");
       exit (-1);
