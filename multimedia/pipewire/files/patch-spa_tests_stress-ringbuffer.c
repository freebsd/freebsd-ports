--- spa/tests/stress-ringbuffer.c.orig	2022-01-05 10:25:04 UTC
+++ spa/tests/stress-ringbuffer.c
@@ -13,7 +13,8 @@
 
 #ifdef __FreeBSD__
 #include <sys/param.h>
-#if __FreeBSD_version < 1400043
+#if (__FreeBSD_version >= 1400000 && __FreeBSD_version < 1400043) \
+    || (__FreeBSD_version < 1300523)
 static int sched_getcpu(void) { return -1; };
 #endif
 #endif
