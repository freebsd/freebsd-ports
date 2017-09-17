--- src/taucs_timer.c.orig	2003-09-01 10:28:54 UTC
+++ src/taucs_timer.c
@@ -245,36 +245,35 @@ double timer()
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/types.h>                                                 
-#include <sys/timeb.h>                                                 
 
 double taucs_wtime()
 {
-  struct timeb T;
+  struct timeval T;
   /*static int first_time    = 1;*/
   /*  static time_t start_time, time_diff;
-      static time_t start_mill, mill_diff;
+      static time_t start_micro, micro_diff;
   */
 
   static time_t time_diff;
-  static time_t mill_diff;
+  static time_t micro_diff;
   /*int    rc;*/
   double dt;
   
-  (void) ftime( &T );
+  (void) gettimeofday( &T,NULL );
   /*
   if (first_time) {
     first_time = 0;
-    start_time = T.time;
-    start_mill = T.millitm;
+    start_time = T.tv_sec;
+    start_micro = T.tv_usec;
   }
 
-  time_diff = T.time - start_time;
-  mill_diff = T.millitm - start_mill; 
+  time_diff = T.tv_sec - start_time;
+  micro_diff = T.tv_usec - start_micro; 
   */
-  time_diff = T.time;
-  mill_diff = T.millitm;
+  time_diff = T.tv_sec;
+  micro_diff = T.tv_usec;
 
-  dt = ((double) time_diff) + (1e-3) * ((double) mill_diff);
+  dt = ((double) time_diff) + (1e-6) * ((double) micro_diff);
 
   return dt;
 }
