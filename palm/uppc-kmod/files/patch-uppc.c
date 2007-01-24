--- uppc.c.orig	Sun Sep 12 05:39:44 2004
+++ uppc.c	Wed Jan 24 02:31:02 2007
@@ -93,6 +93,10 @@
 
 #include <dev/usb/ucomvar.h>
 
+#ifndef USBDEVNAME
+#define USBDEVNAME	device_get_nameunit
+#endif
+
 static int uppcrtvendor = 0;
 static int uppcrtproduct = 0;
 
