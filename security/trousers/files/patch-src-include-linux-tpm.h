--- src/include/linux/tpm.h.orig	2014-04-24 18:05:44 UTC
+++ src/include/linux/tpm.h
@@ -20,6 +20,8 @@
 #include <linux/ioctl.h>
 #elif (defined (__OpenBSD__) || defined (__FreeBSD__))
 #include <sys/ioctl.h>
+#elif (defined (SOLARIS))
+#include <sys/ioccom.h>
 #endif
 
 /* ioctl commands */
