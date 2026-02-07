--- src/include/linux/tpm.h.orig	2016-11-19 03:09:49 UTC
+++ src/include/linux/tpm.h
@@ -20,6 +20,8 @@
 #include <linux/ioctl.h>
 #elif (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <sys/ioctl.h>
+#elif (defined (SOLARIS))
+#include <sys/ioccom.h>
 #endif
 
 /* ioctl commands */
