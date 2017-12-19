--- src/buses.cpp.orig	2017-12-17 21:14:26 UTC
+++ src/buses.cpp
@@ -38,7 +38,11 @@
 
 #include <tuple>
 
+#if defined(__FreeBSD__)
+#define USB_DEVICE_START "usbus"
+#else
 #define USB_DEVICE_START "usbmon"
+#endif
 
 static size_t g_len_usb_dev_start = 5; // strlen(USB_DEVICE_START
 
