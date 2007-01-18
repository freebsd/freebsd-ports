--- uppc.c.orig	Thu Jan 18 16:07:01 2007
+++ uppc.c	Thu Jan 18 16:12:10 2007
@@ -62,6 +62,10 @@
 #define USB_PRODUCT_TOSHIBA_E330	0x0707
 #define USB_PRODUCT_TOSHIBA_E740	0x0706
 
+#ifndef USBDEVNAME
+#define USBDEVNAME	device_get_nameunit
+#endif
+
 #include <sys/cdefs.h>
 
 #include <sys/param.h>
