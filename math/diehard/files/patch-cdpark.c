--- cdpark.c.orig	2019-08-03 10:37:50 UTC
+++ cdpark.c
@@ -36,8 +36,8 @@ void park(char *filename)
   puts("\t|ble, provides input to a KSTEST based on a sample of 10.     |");
   puts("\t|-------------------------------------------------------------|\n");
   
-  printf("\t\tCDPARK: result of %d tests on file %s\n", no_obs, filename);
-  printf("\t  (Of %d tries, the average no. of successes", no_trials);
+  printf("\t\tCDPARK: result of %lu tests on file %s\n", no_obs, filename);
+  printf("\t  (Of %lu tries, the average no. of successes", no_trials);
   printf(" should be \n\t   %.1f with sigma=%.1f)\n\n", mu, sigma);
   printf("\t   No. succeses\t\tz-score\t\tp-value\n");
 
@@ -79,7 +79,7 @@ void park(char *filename)
     z=(no_succ-mu)/sigma;
     p[i-1]=1-Phi(z);
 
-    printf("\t\t%d\t\t% .4f\t\t%f\n", no_succ, z, p[i-1]);
+    printf("\t\t%lu\t\t% .4f\t\t%f\n", no_succ, z, p[i-1]);
   }
   uni("close");
 
@@ -88,11 +88,11 @@ void park(char *filename)
   mean=(real)sum/no_obs;
   var=(real)ss/no_obs-mean*mean;
 
-  printf("\t  Square side=%d, avg. no. parked=%.2f", side, mean);
+  printf("\t  Square side=%lu, avg. no. parked=%.2f", side, mean);
   printf(" sample std.=%.2f\n", sqrt(var)); 
  
   pvalue=KStest(p, no_obs);
-  printf("\t     p-value of the KSTEST for those %d", no_obs); 
+  printf("\t     p-value of the KSTEST for those %lu", no_obs); 
   printf(" p-values: %f\n\n", pvalue);
     
   return;
