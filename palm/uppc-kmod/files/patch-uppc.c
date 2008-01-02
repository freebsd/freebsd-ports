--- uppc.c.orig	2008-01-02 17:34:35.000000000 +0000
+++ uppc.c	2008-01-02 17:34:47.000000000 +0000
@@ -62,6 +62,8 @@
 #define USB_PRODUCT_TOSHIBA_E330	0x0707
 #define USB_PRODUCT_TOSHIBA_E740	0x0706
 
+#define USB_PRODUCT_SAMSUNG_I730	0x6662
+
 #include <sys/cdefs.h>
 
 #include <sys/param.h>
@@ -84,6 +86,10 @@
 
 #include <sys/sysctl.h>
 
+#if __FreeBSD_version >= 700049
+#include <dev/usb/usb_port.h>
+#endif
+
 #include <dev/usb/usb.h>
 
 #include <dev/usb/usbcdc.h>
@@ -93,6 +99,10 @@
 
 #include <dev/usb/ucomvar.h>
 
+#ifndef USBDEVNAME
+#define USBDEVNAME	device_get_nameunit
+#endif
+
 static int uppcrtvendor = 0;
 static int uppcrtproduct = 0;
 
@@ -166,6 +176,7 @@
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_UNK }, 0},
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_E330 }, 0},
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_E740 }, 0},
+	{{ USB_VENDOR_SAMSUNG, USB_PRODUCT_SAMSUNG_I730 }, 0},
 };
 
 /* The ucom_softc structure plus anything else we might need. */
