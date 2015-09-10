--- lib/libv4lconvert/control/libv4lcontrol.c.orig	2014-07-26 21:33:00.000000000 +0200
+++ lib/libv4lconvert/control/libv4lcontrol.c	2015-01-11 09:40:05.521158993 +0100
@@ -361,6 +361,16 @@
 		unsigned short *vendor_id, unsigned short *product_id,
 		int *speed)
 {
+#ifdef __FreeBSD__
+#define WEBCAMD_IOCTL_GET_USB_VENDOR_ID _IOR('q', 250, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_PRODUCT_ID _IOR('q', 251, unsigned short)
+#define WEBCAMD_IOCTL_GET_USB_SPEED _IOR('q', 252, unsigned int)
+	if (ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_VENDOR_ID, vendor_id) == 0 &&
+	    ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_PRODUCT_ID, product_id) == 0 &&
+	    ioctl(data->fd, WEBCAMD_IOCTL_GET_USB_SPEED, speed) == 0)
+		return (1);
+	return (0);
+#else
 	FILE *f;
 	int i, minor;
 	struct stat st;
@@ -457,6 +467,7 @@
 		return 0; /* Should never happen */
 
 	return 1;
+#endif
 }
 
 /*
