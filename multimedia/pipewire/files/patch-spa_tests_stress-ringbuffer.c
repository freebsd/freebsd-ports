--- spa/tests/stress-ringbuffer.c.orig	2021-11-11 04:21:29.000000000 -0800
+++ spa/tests/stress-ringbuffer.c	2021-12-12 12:11:15.939268000 -0800
@@ -12,7 +12,10 @@
 #define MAX_VALUE 0x10000
 
 #ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 1400043
 static int sched_getcpu(void) { return -1; };
+#endif
 #endif
 
 static struct spa_ringbuffer rb;
