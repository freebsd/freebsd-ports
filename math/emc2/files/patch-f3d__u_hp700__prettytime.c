--- ./f3d/u_hp700/prettytime.c.orig	2010-08-31 08:51:31.000000000 -0400
+++ ./f3d/u_hp700/prettytime.c	2010-08-31 08:52:32.000000000 -0400
@@ -6,7 +6,7 @@
 {
     time_t timevar;
     struct tm *pttm;
-    char buffer[12];
+    char buffer[13];
 
     timevar=time(&timevar);
     pttm = localtime(&timevar);
@@ -14,6 +14,6 @@
     sprintf(buffer,"%02d%02d%02d000000",pttm->tm_hour,
                                   pttm->tm_min,
                                   pttm->tm_sec);
-    bcopy (buffer, timeret, 12);
+    bcopy (buffer, timeret, 13);
 }
       
