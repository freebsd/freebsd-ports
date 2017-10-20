--- drivers/libusb.h.orig	2015-12-29 12:08:34 UTC
+++ drivers/libusb.h
@@ -36,6 +36,24 @@
 
 #include <usb.h>	/* libusb header file */
 
+/* libusb 1.0 errors used by FreeBSD */
+enum libusb_error {
+        LIBUSB_SUCCESS = 0,
+        LIBUSB_ERROR_IO = -1,
+        LIBUSB_ERROR_INVALID_PARAM = -2,
+        LIBUSB_ERROR_ACCESS = -3,
+        LIBUSB_ERROR_NO_DEVICE = -4,
+        LIBUSB_ERROR_NOT_FOUND = -5,
+        LIBUSB_ERROR_BUSY = -6,
+        LIBUSB_ERROR_TIMEOUT = -7,
+        LIBUSB_ERROR_OVERFLOW = -8,
+        LIBUSB_ERROR_PIPE = -9,
+        LIBUSB_ERROR_INTERRUPTED = -10,
+        LIBUSB_ERROR_NO_MEM = -11,
+        LIBUSB_ERROR_NOT_SUPPORTED = -12,
+        LIBUSB_ERROR_OTHER = -99,
+};
+
 extern upsdrv_info_t comm_upsdrv_info; 
 
 /*!
