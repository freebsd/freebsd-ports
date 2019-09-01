--- cdomso.c.orig	2019-08-03 10:18:08 UTC
+++ cdomso.c
@@ -138,7 +138,7 @@ real monky_stat(char *filename, char *te
       }
 
       z=(no_mswds-mean)/std;
-      printf("\t%d to %d  \t\t%d ", 33-rt-bits_pl, 32-rt, no_mswds);
+      printf("\t%lu to %lu  \t\t%lu ", 33-rt-bits_pl, 32-rt, no_mswds);
       printf("\t\t% .4f\t\t%f\n", z, 1-Phi(z));
     }
  
@@ -151,11 +151,11 @@ real monky_stat(char *filename, char *te
   printf("\t------------------------------");
   printf("-----------------------------------\n");
   
-  return;
+  return 0;
 }
 
 /* type "OPSO" for OPSO test and so on */
-void monky(char *filename, char *test)
+int monky(char *filename, char *test)
 {
   const int no_tests=1;
 
@@ -165,7 +165,7 @@ void monky(char *filename, char *test)
 
   monky_stat(filename, test, no_tests);
 
-  return;
+  return 0;
 
 }
 
