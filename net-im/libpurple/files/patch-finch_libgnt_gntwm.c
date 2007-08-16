--- finch/libgnt/gntwm.c.orig	2007-08-16 02:19:22.000000000 -0400
+++ finch/libgnt/gntwm.c	2007-08-16 02:19:38.000000000 -0400
@@ -21,7 +21,7 @@
  */
 
 #define _GNU_SOURCE
-#if defined(__APPLE__) || defined(__unix__)
+#if (defined(__APPLE__) || defined(__unix__)) && !defined(__FreeBSD__)
 #define _XOPEN_SOURCE_EXTENDED
 #endif
 
