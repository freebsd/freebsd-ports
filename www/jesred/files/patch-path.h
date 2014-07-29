--- path.h.orig	Sat Jul 25 03:03:13 1998
+++ path.h	Mon Nov  8 18:15:30 1999
@@ -7,6 +7,8 @@
 
 /* change this to the path, which contains your jesred.conf */
 
+#ifndef DEFAULT_PATH
 #define DEFAULT_PATH "/local/squid/etc"
+#endif
 
 #endif
