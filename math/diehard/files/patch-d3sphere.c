--- d3sphere.c.orig	2019-08-03 10:59:28 UTC
+++ d3sphere.c
@@ -61,7 +61,7 @@ void sphere(char *filename)
 
       r3=dmin*sqrt(dmin);
       p[i-1]=1-exp(-MIN(r3/30., 20));
-      printf("\t\t   %d\t\t%.3f\t\t%f\n", i, r3, p[i-1]);
+      printf("\t\t   %lu\t\t%.3f\t\t%f\n", i, r3, p[i-1]);
   }
   uni("close");
 
@@ -69,7 +69,7 @@ void sphere(char *filename)
   
   puts("\t--------------------------------------------------------------");
   pvalue=KStest(p,no_obs);
-  printf("\t\tp-value for KS test on those %d p-values: %f", no_obs, pvalue);
+  printf("\t\tp-value for KS test on those %lu p-values: %f", no_obs, pvalue);
   puts("\n");
     
   free(p);
