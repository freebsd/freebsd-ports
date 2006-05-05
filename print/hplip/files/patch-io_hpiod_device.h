--- io/hpiod/device.h.orig	Tue Feb 28 19:40:55 2006
+++ io/hpiod/device.h	Sun Apr  2 23:38:58 2006
@@ -72,6 +72,9 @@
    int AltSetting;
    int urb_write_active;             /* 0=no, 1=yes */
 #if defined(__APPLE__) && defined(__MACH__)
+
+#elif defined(__FreeBSD__)
+
 #else
    struct usbdevfs_urb urb_write;     /* host to device */
    struct usbdevfs_urb urb_read;     /* device to host */
