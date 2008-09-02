--- input-oss.c.orig	2008-09-02 14:40:15.000000000 +0100
+++ input-oss.c	2008-09-02 14:41:52.000000000 +0100
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
