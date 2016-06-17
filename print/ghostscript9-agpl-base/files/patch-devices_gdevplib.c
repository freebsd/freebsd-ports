--- devices/gdevplib.c.orig	2015-03-30 08:21:24 UTC
+++ devices/gdevplib.c
@@ -156,7 +156,11 @@ void __aebi_memmove(void *dest, const vo
 
 #ifdef  TESTING_WITH_NO_BAND_DONOR
 
+#if !defined(__FreeBSD__)
 #include <malloc_.h>
+#else
+#include <stdlib.h>
+#endif
 
 static void *my_buffer;
 
