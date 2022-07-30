--- random.c.orig	2022-07-25 15:45:07 UTC
+++ random.c
@@ -28,6 +28,9 @@ typedef unsigned int __u32;
 #endif
 #include <sys/random.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/random.h>
+#endif
 
 static void msleep(unsigned int msecs)
 {
