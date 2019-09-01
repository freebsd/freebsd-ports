--- cdosum.c.orig	2019-08-03 10:56:11 UTC
+++ cdosum.c
@@ -64,7 +64,7 @@ void osum(char *filename)
     }
 
     pv[i-1]=KStest(p, no_num);
-    printf("\t\t\t  %d \t\t\t%f\n", i, pv[i-1]);
+    printf("\t\t\t  %lu \t\t\t%f\n", i, pv[i-1]);
   }
   uni("close");
 
@@ -75,7 +75,7 @@ void osum(char *filename)
   tmp=KStest(pv, no_obs);
   free(pv);
 
-  printf("\t\tp-value for %d kstests on %d kstests:%f\n", no_obs, no_sum, tmp);
+  printf("\t\tp-value for %lu kstests on %lu kstests:%f\n", no_obs, no_sum, tmp);
 
   return;
 }
