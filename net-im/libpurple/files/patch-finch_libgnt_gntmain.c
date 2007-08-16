--- finch/libgnt/gntmain.c.orig	2007-08-16 02:18:26.000000000 -0400
+++ finch/libgnt/gntmain.c	2007-08-16 02:18:42.000000000 -0400
@@ -21,7 +21,7 @@
  */
 
 #define _GNU_SOURCE
-#if defined(__APPLE__) || defined(__unix__)
+#if (defined(__APPLE__) || defined(__unix__)) && !defined(__FreeBSD__)
 #define _XOPEN_SOURCE_EXTENDED
 #endif
 
