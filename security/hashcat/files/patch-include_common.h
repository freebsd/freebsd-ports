--- include/common.h.orig	2016-06-28 09:47:32 UTC
+++ include/common.h
@@ -51,6 +51,11 @@
 #include <mach/mach.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <termios.h>
+#include <sys/ioctl.h>
+#endif
+
 typedef void *OCL_LIB;
 
 #ifdef HAVE_HWMON
