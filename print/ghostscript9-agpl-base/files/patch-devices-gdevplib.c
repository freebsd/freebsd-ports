--- devices/gdevplib.c.orig	2015-03-30 17:21:24.000000000 +0900
+++ devices/gdevplib.c	2015-07-14 08:51:50.711673000 +0900
@@ -156,7 +156,11 @@
 
 #ifdef  TESTING_WITH_NO_BAND_DONOR
 
+#if !defined(__FreeBSD__)
 #include <malloc_.h>
+#else
+#include <stdlib.h>
+#endif
 
 static void *my_buffer;
 
