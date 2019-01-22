--- libxfcegui4/xfce-exec.c.orig	2012-04-28 20:10:43 UTC
+++ libxfcegui4/xfce-exec.c
@@ -79,7 +79,7 @@ child_setup_sync(gpointer user_data)
 #ifndef G_OS_WIN32
     gchar *dpyname = user_data;
     
-    xfce_setenv ("DISPLAY", dpyname, TRUE);
+    g_setenv ("DISPLAY", dpyname, TRUE);
 #endif
 }
 
