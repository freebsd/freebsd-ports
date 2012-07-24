--- src/util.c.orig	2012-07-24 13:34:08.000000000 +0400
+++ src/util.c	2012-07-24 13:34:29.000000000 +0400
@@ -48,6 +48,10 @@
 #include <libintl.h>
 #endif
 
+#ifdef TIOCGSIZE
+#undef TIOCGSIZE
+#endif
+
 /*
  * Return the longest of the two parameters
  * @a: first element to compare
