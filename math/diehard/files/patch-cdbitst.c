--- cdbitst.c.orig	2019-08-03 10:34:33 UTC
+++ cdbitst.c
@@ -41,8 +41,8 @@ void bitst(char *filename)
   puts("\t|-------------------------------------------------------------|\n");
 
   printf("\t\tTHE OVERLAPPING 20-TUPLES BITSTREAM  TEST for %s\n", filename);
-  printf("\t (%d bits/word, %d words", nb_pw, no_wds);
-  printf(" %d bitstreams.", no_obs );
+  printf("\t (%lu bits/word, %lu words", nb_pw, no_wds);
+  printf(" %lu bitstreams.", no_obs );
   printf(" No. missing words \n\t  should average %.2f", mean);
   printf(" with sigma=%.2f.)\n", std);
   puts("\t----------------------------------------------------------------");
@@ -80,7 +80,7 @@ void bitst(char *filename)
     }
 
     z=(no_mswds-mean)/std;
-    printf("\t   %d\t\t%d \t\t\t% .2f\t\t%f\n", i, no_mswds, z, 1-Phi(z));
+    printf("\t   %lu\t\t%lu \t\t\t% .2f\t\t%f\n", i, no_mswds, z, 1-Phi(z));
   }
 
   uni("close");
