--- libpisock/freebsdusb.c.orig	2006-10-12 16:21:22.000000000 +0200
+++ libpisock/freebsdusb.c	2009-06-18 13:05:35.383212316 +0200
@@ -48,7 +48,15 @@
 
 #if defined(__FreeBSD__)
 /* freebsd usb header */
+#include <sys/param.h>
 #include <dev/usb/usb.h>
+#if __FreeBSD_version+0 >= 800092
+#include <dev/usb/usb_ioctl.h>
+#else
+/* redefine to legacy names, so this continues to build on FreeBSD 7.x */
+#define USB_SET_TX_TIMEOUT USB_SET_TIMEOUT
+#define USB_SET_RX_SHORT_XFER USB_SET_SHORT_XFER
+#endif
 #define MAX_BUF 256
 #endif
 
@@ -173,7 +181,7 @@
 	   will don't know exactly
 	what is coming so we can't specify exact byte amounts */
 	i = 1;
-	if (ioctl(endpoint_fd, USB_SET_SHORT_XFER, &i) < 0) {
+	if (ioctl(endpoint_fd, USB_SET_RX_SHORT_XFER, &i) < 0) {
 		LOG((PI_DBG_DEV, PI_DBG_LVL_WARN,
 		 "DEV USB_SET_SHORT_XFER USB FreeBSD fd: %d failed\n",
 			endpoint_fd));
@@ -182,7 +190,7 @@
 	/* 0 timeout value will cause us the wait until the device has data
            available or is disconnected */
 	i = 0;
-	if (ioctl(endpoint_fd, USB_SET_TIMEOUT, &i) < 0) {
+	if (ioctl(endpoint_fd, USB_SET_TX_TIMEOUT, &i) < 0) {
 		LOG((PI_DBG_DEV, PI_DBG_LVL_WARN,
 		 "DEV USB_SET_TIMEOUT USB FreeBSD fd: %d failed\n",
 			endpoint_fd));
