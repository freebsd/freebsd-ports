--- ./f3d/u_hp700/prettydate.c.orig	2010-08-31 08:51:18.000000000 -0400
+++ ./f3d/u_hp700/prettydate.c	2010-08-31 08:52:44.000000000 -0400
@@ -6,7 +6,7 @@
 {
     time_t timevar;
     struct tm *pttm;
-    char buffer[6];
+    char buffer[7];
 
     timevar=time(&timevar);
     pttm = localtime(&timevar);
@@ -14,6 +14,6 @@
     sprintf(buffer,"%02d%02d%02d",pttm->tm_year % 100,
                                   pttm->tm_mon+1,
                                   pttm->tm_mday);
-    bcopy (buffer, date, 6);
+    bcopy (buffer, date, 7);
 }
       
