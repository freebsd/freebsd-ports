--- ./libxfcegui4/xfce-exec.c.orig	2012-04-28 20:10:43.000000000 +0000
+++ ./libxfcegui4/xfce-exec.c	2014-03-24 21:25:39.000000000 +0000
@@ -79,7 +79,7 @@
 #ifndef G_OS_WIN32
     gchar *dpyname = user_data;
     
-    xfce_setenv ("DISPLAY", dpyname, TRUE);
+    g_setenv ("DISPLAY", dpyname, TRUE);
 #endif
 }
 
