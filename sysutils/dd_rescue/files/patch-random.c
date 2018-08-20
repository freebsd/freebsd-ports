--- random.c.orig	2015-09-10 15:51:08 UTC
+++ random.c
@@ -22,6 +22,9 @@ typedef unsigned int __u32;
 #ifdef HAVE_LINUX_RANDOM_H
 #include <linux/random.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/random.h>
+#endif
 
 static void msleep(unsigned int msecs)
 {
