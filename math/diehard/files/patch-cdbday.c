--- cdbday.c.orig	2019-08-03 11:00:43 UTC
+++ cdbday.c
@@ -83,8 +83,8 @@ void bday(char *filename)
   puts("\t|------------------------------------------------------------ |\n");
  
   printf("\t\tRESULTS OF BIRTHDAY SPACINGS TEST FOR %s\n", filename);
-  printf("\t(no_bdays=%d, no_days/yr=2^%d,",no_bday, no_bits);
-  printf(" lambda=%.2f, sample size=%d)\n\n", lambda, no_obs);
+  printf("\t(no_bdays=%lu, no_days/yr=2^%lu,",no_bday, no_bits);
+  printf(" lambda=%.2f, sample size=%lu)\n\n", lambda, no_obs);
   printf("\tBits used\tmean\t\tchisqr\t\tp-value\n");
 
   obs=(counter*)malloc(no_obs*sizeof(counter));
@@ -121,7 +121,7 @@ void bday(char *filename)
 
     p[rt]=P_fit(lambda, obs, no_obs);
 
-    printf("\t %d to %d", 33-no_bits-rt,32-rt);
+    printf("\t %lu to %d", 33-no_bits-rt,32-rt);
     printf("\t%.2f\t\t%.4f\t\t%f\n", (real)sum/no_obs, chi_fit, p[rt]);   
 
   }
@@ -134,7 +134,7 @@ void bday(char *filename)
 
   printf("\n\t\t\tdegree of freedoms is: %d\n", dgf);
   puts("\t---------------------------------------------------------------");
-  printf("\t\tp-value for KStest on those %d p-values: %f",32-no_bits+1,pvalue);
+  printf("\t\tp-value for KStest on those %lu p-values: %f",32-no_bits+1,pvalue);
   puts("\n"); 
 
   free(p);
