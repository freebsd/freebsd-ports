--- libpisock/freebsdusb.c.orig	2006-10-12 06:21:22.000000000 -0800
+++ libpisock/freebsdusb.c	2009-03-02 10:06:01.000000000 -0900
@@ -48,7 +48,12 @@
 
 #if defined(__FreeBSD__)
 /* freebsd usb header */
+#include <sys/param.h>
+#if __FreeBSD_version+0 >= 800064
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
 #define MAX_BUF 256
 #endif
 
