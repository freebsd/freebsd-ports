--- src/trackers.c.orig	Wed Feb 21 00:25:03 2001
+++ src/trackers.c	Tue Jun 24 22:07:41 2003
@@ -134,8 +134,6 @@
   }
   return 0;
 }
-#else
-extern int strcasestr(const char *a, const char*b);
 #endif
 
 static void show_servers(){
