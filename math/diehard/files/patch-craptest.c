--- craptest.c.orig	2019-08-03 10:04:26 UTC
+++ craptest.c
@@ -77,7 +77,7 @@ void craptest(char *filename)
 
   printf("\t\tRESULTS OF CRAPS TEST FOR %s \n", filename);
   printf("\tNo. of wins:  Observed\tExpected\n");
-  printf("\t                 %d        %f\n", no_win, mean);
+  printf("\t                 %lu       %f\n", no_win, mean);
 
   pvalue_w=1-Phi(t);
   printf("\t\tz-score=%6.3f, pvalue=%7.5f\n", t, pvalue_w);
@@ -93,7 +93,7 @@ void craptest(char *filename)
     mean=no_games*Ef[i];
     t=(f[i]-mean)*(f[i]-mean)/mean;
     sum+=t;     
-    printf("\t%d\t%d\t\t%.1f",i+1, f[i], mean);
+    printf("\t%lu\t%lu\t\t%.1f",i+1, f[i], mean);
     printf("\t\t%.3f\t\t%.3f\n", t, sum);
   }
 
