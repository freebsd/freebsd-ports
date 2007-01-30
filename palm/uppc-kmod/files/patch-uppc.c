--- uppc.c.orig	Sun Sep 12 05:39:44 2004
+++ uppc.c	Thu Jan 25 23:40:56 2007
@@ -62,6 +62,8 @@
 #define USB_PRODUCT_TOSHIBA_E330	0x0707
 #define USB_PRODUCT_TOSHIBA_E740	0x0706
 
+#define USB_PRODUCT_SAMSUNG_I730	0x6662
+
 #include <sys/cdefs.h>
 
 #include <sys/param.h>
@@ -93,6 +95,10 @@
 
 #include <dev/usb/ucomvar.h>
 
+#ifndef USBDEVNAME
+#define USBDEVNAME	device_get_nameunit
+#endif
+
 static int uppcrtvendor = 0;
 static int uppcrtproduct = 0;
 
@@ -166,6 +172,7 @@
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_UNK }, 0},
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_E330 }, 0},
 	{{ USB_VENDOR_TOSHIBA, USB_PRODUCT_TOSHIBA_E740 }, 0},
+	{{ USB_VENDOR_SAMSUNG, USB_PRODUCT_SAMSUNG_I730 }, 0},
 };
 
 /* The ucom_softc structure plus anything else we might need. */
