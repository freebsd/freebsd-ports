--- kernel/linux_usb.c.orig	2022-07-13 09:52:22.000000000 -0700
+++ kernel/linux_usb.c	2026-08-19 07:29:51.615032000 -0700
@@ -29,6 +29,8 @@
 
 #include <linux/input.h>
 
+#include <sys/param.h>
+
 #define to_urb(d) container_of(d, struct urb, kref)
 
 static int min_bufsize;
@@ -335,7 +337,11 @@
 
 	index_copy = index;
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1600020
+	pbe = libusb20_be_alloc_default(NULL);
+#else
 	pbe = libusb20_be_alloc_default();
+#endif
 	if (pbe == NULL)
 		return (-ENXIO);
 
