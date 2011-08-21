--- a/usbredirhost/usbredirhost.c
+++ b/usbredirhost/usbredirhost.c
@@ -27,6 +27,71 @@
 #include <unistd.h>
 #include "usbredirhost.h"
 
+/*
+ * passing actual enum libusb_speed libusb_get_device_speed() return
+ * values other than LIBUSB_SPEED_UNKNOWN causes qemu 0.15.0 to
+ * complain when redirecting usb 2.0 devices when ehci isn't enabled
+ * (-readconfig docs/ich9-ehci-uhci.cfg, which breaks at least
+ * FreeBSD 8 guests and hangs at boot in seabios(?) when redirecting
+ * an usb 2.0 flashkey) - it says:
+ *
+ *	qemu: Warning: speed mismatch trying to attach usb device USB Redirection Device to bus usb.0
+ *
+ * and ignores the redirected device.  Thus, for now always assume
+ * speed unknown:
+ */
+#define IGNORE_LIBUSB_GET_DEVICE_SPEED
+
+/* The following is only interesting once the above is fixed: */
+#ifndef	IGNORE_LIBUSB_GET_DEVICE_SPEED
+#define	HAVE_LIBUSB_GET_DEVICE_SPEED
+
+#ifdef __FreeBSD__
+/* #undef this if libusb_get_device_speed() is missing in your
+ * version of FreeBSD (not relevant if IGNORE_LIBUSB_GET_DEVICE_SPEED
+ * is defined) */
+/* #undef HAVE_LIBUSB_GET_DEVICE_SPEED */
+
+#ifndef	HAVE_LIBUSB_GET_DEVICE_SPEED
+#include <libusb20.h>
+#define	HAVE_SRC	/* this only works if system sources are available */
+#ifdef	HAVE_SRC
+#include "/usr/src/lib/libusb/libusb10.h"
+#endif
+
+enum libusb_speed {
+	LIBUSB_SPEED_UNKNOWN = 0,
+	LIBUSB_SPEED_LOW = 1,
+	LIBUSB_SPEED_FULL = 2,
+	LIBUSB_SPEED_HIGH = 3,
+	LIBUSB_SPEED_SUPER = 4,
+};
+
+enum libusb_speed libusb_get_device_speed(libusb_device *dev)
+{
+#ifdef HAVE_SRC
+	if (dev == NULL)
+		return (LIBUSB_SPEED_UNKNOWN);	/* should not happen */
+
+	switch (libusb20_dev_get_speed(dev->os_priv)) {
+	case LIBUSB20_SPEED_LOW:
+		return (LIBUSB_SPEED_LOW);
+	case LIBUSB20_SPEED_FULL:
+		return (LIBUSB_SPEED_FULL);
+	case LIBUSB20_SPEED_HIGH:
+		return (LIBUSB_SPEED_HIGH);
+	case LIBUSB20_SPEED_SUPER:
+		return (LIBUSB_SPEED_SUPER);
+	default:
+		break;
+	}
+#endif
+	return (LIBUSB_SPEED_UNKNOWN);
+}
+#endif
+#endif
+#endif
+
 #define MAX_ENDPOINTS        32
 #define MAX_INTERFACES       32 /* Max 32 endpoints and thus interfaces */
 #define CTRL_TIMEOUT       5000 /* USB specifies a 5 second max timeout */
@@ -487,6 +552,9 @@ struct usbredirhost *usbredirhost_open(
         return NULL;
     }
 
+#ifdef IGNORE_LIBUSB_GET_DEVICE_SPEED
+    device_connect.speed = usb_redir_speed_unknown;
+#else
     speed = libusb_get_device_speed(host->dev);
     switch (speed) {
     case LIBUSB_SPEED_LOW:
@@ -500,6 +568,7 @@ struct usbredirhost *usbredirhost_open(
     default:
         device_connect.speed = usb_redir_speed_unknown;
     }
+#endif
     device_connect.device_class = desc.bDeviceClass;
     device_connect.device_subclass = desc.bDeviceSubClass;
     device_connect.device_protocol = desc.bDeviceProtocol;
