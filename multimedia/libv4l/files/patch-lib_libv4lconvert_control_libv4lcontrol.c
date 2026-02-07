--- lib/libv4lconvert/control/libv4lcontrol.c.orig	2020-04-09 16:29:54 UTC
+++ lib/libv4lconvert/control/libv4lcontrol.c
@@ -360,6 +360,16 @@ static int v4lcontrol_get_usb_info(struct v4lcontrol_d
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
 	int i, minor_dev;
 	struct stat st;
@@ -456,6 +466,7 @@ static int v4lcontrol_get_usb_info(struct v4lcontrol_d
 		return 0; /* Should never happen */
 
 	return 1;
+#endif
 }
 
 /*
