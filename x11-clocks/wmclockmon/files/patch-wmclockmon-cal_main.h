--- wmclockmon-cal/main.h.orig	2022-12-03 21:02:51 UTC
+++ wmclockmon-cal/main.h
@@ -9,7 +9,7 @@
 #include <sys/time.h>
 
 
-struct tm *timeinfos;
+extern struct tm *timeinfos;
 
 void quit_app();
 
