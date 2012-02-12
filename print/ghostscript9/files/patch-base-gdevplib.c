--- base/gdevplib.c.orig	2012-02-08 17:48:47.000000000 +0900
+++ base/gdevplib.c	2012-02-13 01:23:46.000000000 +0900
@@ -151,7 +151,11 @@
 
 #ifdef  TESTING_WITH_NO_BAND_DONOR
 
+#if !defined(__FreeBSD__)
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 
 static void *my_buffer;
 
