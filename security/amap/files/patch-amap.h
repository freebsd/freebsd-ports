--- amap.h.orig	Tue Jun 10 17:05:40 2003
+++ amap.h	Tue Jun 10 17:06:25 2003
@@ -57,7 +57,8 @@
 //-----------------------------------------
 
 // where are my appdefs files? all entries must end with a slash!
-char *searchpath[14] = { "./", "/etc/", "/usr/etc/", "/usr/local/etc/",
+char *searchpath[15] = { "./", "PREFIX/share/amap/", "/etc/", "/usr/etc/",
+  "/usr/local/etc/",
   "/opt/etc/", "/usr/local/amap/", "/opt/amap/",
   "/usr/local/lib/", "/usr/local/lib/amap/",
   "/usr/lib/amap/", "/usr/local/bin/",
