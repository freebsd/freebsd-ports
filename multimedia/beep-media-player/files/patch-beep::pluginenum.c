--- beep/pluginenum.c.orig	Wed Dec 24 15:03:17 2003
+++ beep/pluginenum.c	Sat Feb  7 22:08:41 2004
@@ -238,6 +238,7 @@
 
 
 #ifndef DISABLE_USER_PLUGIN_DIR
+if(0) {
     dir = g_build_filename(g_get_home_dir(), BMP_RCPATH, "plugins");
     bmp_scan_plugins(dir);
     g_free(dir);
@@ -259,6 +260,7 @@
 	g_free(dir);
     }
     dirsel = 0;
+}
 #endif
 
     while (plugin_dir_list[dirsel]) {
