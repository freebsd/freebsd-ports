--- base/gdevplib.c.orig	2012-08-08 08:01:36 UTC
+++ base/gdevplib.c
@@ -153,7 +153,11 @@ void __aebi_memmove(void *dest, const vo
 
 #ifdef  TESTING_WITH_NO_BAND_DONOR
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 
 static void *my_buffer;
 
