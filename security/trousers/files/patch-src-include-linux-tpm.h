--- src/include/linux/tpm.h.orig	2010-01-29 01:27:51.000000000 +0900
+++ src/include/linux/tpm.h	2010-10-24 21:04:04.821560671 +0900
@@ -20,6 +20,8 @@
 #include <linux/ioctl.h>
 #elif (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <sys/ioctl.h>
+#elif (defined (SOLARIS))
+#include <sys/ioccom.h>
 #endif
 
 /* ioctl commands */
