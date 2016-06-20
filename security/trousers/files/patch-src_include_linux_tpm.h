--- src/include/linux/tpm.h.orig	2016-06-20 15:21:26 UTC
+++ src/include/linux/tpm.h
@@ -20,6 +20,8 @@
 #include <linux/ioctl.h>
 #elif (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <sys/ioctl.h>
+#elif (defined (SOLARIS))
+#include <sys/ioccom.h>
 #endif
 
 /* ioctl commands */
