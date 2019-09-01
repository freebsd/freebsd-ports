--- cdoperm5.c.orig	2019-08-03 10:52:40 UTC
+++ cdoperm5.c
@@ -71,21 +71,21 @@ void operm5(char *filename)
   puts("\t|rank 99).  This version uses 1,000,000 integers, twice.      |");
   puts("\t|-------------------------------------------------------------|\n");
 
-  printf("\t\t\tOPERM5 test for file \n", filename);
+  printf("%s \t\t\tOPERM5 test for file \n", filename);
   puts("\t\t  (For samples of 1,000,000 consecutive 5-tuples)\n");
 
   infile=fopen("operm5.cov", "r");
 
   for(i=0; i<60; ++i){
     for(j=i; j<60; ++j){
-      fscanf(infile, "%d", &A[i][j]);
+      fscanf(infile, "%lu", &A[i][j]);
       A[j][i]=A[i][j];
     }
   }
 
   for(i=0; i<60; ++i){
     for(j=i; j<60; ++j){
-      fscanf(infile, "%d", &B[i][j]);
+      fscanf(infile, "%lu", &B[i][j]);
       B[j][i]=B[i][j];
     }
   }
