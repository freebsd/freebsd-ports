--- amap.c.orig	Sun Mar 23 15:42:07 2003
+++ amap.c	Sun Mar 23 16:01:36 2003
@@ -64,7 +64,8 @@
 char banner_string[256];
 
 // where are my appdefs files?
-char *searchpath[12] = { "./", "/etc/", "/usr/etc", "/usr/local/etc/", 
+char *searchpath[13] = { "./", "PREFIX/share/amap/", "/etc/", "/usr/etc",
+                           "/usr/local/etc/", 
                            "/opt/etc/", "/usr/local/amap/", "/opt/amap/",
                            "/usr/local/lib/", "/usr/local/lib/amap/",
                            "/usr/lib/amap/", "/usr/local/bin/", NULL };
