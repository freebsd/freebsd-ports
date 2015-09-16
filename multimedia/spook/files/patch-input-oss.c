--- input-oss.c.orig	2004-12-06 05:58:04 UTC
+++ input-oss.c
@@ -28,7 +28,11 @@
 #include <errno.h>
 #include <pthread.h>
 
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <linux/soundcard.h>
+#endif
 
 #include <event.h>
 #include <log.h>
