--- libv4lconvert/control/libv4lcontrol.c.orig	2012-05-02 21:17:37.000000000 +0200
+++ libv4lconvert/control/libv4lcontrol.c	2012-05-06 08:52:42.000000000 +0200
@@ -345,6 +345,16 @@
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
@@ -434,6 +444,7 @@
 		return 0; /* Should never happen */
 
 	return 1;
+#endif
 }
 
 /*
@@ -456,7 +456,12 @@
 	while (isspace(*start)) start++;
 	n = strlen(start);
 	while (n > 0 && isspace(start[n-1])) --n;
+#ifndef __FreeBSD__
 	trimmed_dmi = strndupa(start, n);
+#else
+	trimmed_dmi = (char *)alloca(n + 1);
+	strlcpy(trimmed_dmi, start, n + 1);
+#endif
 
 	/* find trimmed value */
 	for (entry_ptr = table_entries; *entry_ptr;  entry_ptr++) {
