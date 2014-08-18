--- ./components/usb_service/usb_device_handle.cc.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service/usb_device_handle.cc	2014-08-17 16:54:01.000000000 +0200
@@ -16,7 +16,24 @@
 #include "components/usb_service/usb_interface.h"
 #include "components/usb_service/usb_service.h"
 #include "content/public/browser/browser_thread.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
+
+/* Define for FreeBSD < 9.3, thanks to db@freebsd.org */
+#if defined(OS_FREEBSD) && __FreeBSD_version < 903000
+int libusb_get_string_descriptor(libusb_device_handle *dev,
+  uint8_t descriptor_index, uint16_t lang_id, unsigned char* data, int length) {
+  return libusb_control_transfer(dev,
+    LIBUSB_ENDPOINT_IN | 0x0, /* Endpoint 0 IN */
+    LIBUSB_REQUEST_GET_DESCRIPTOR,
+    (LIBUSB_DT_STRING << 8) | descriptor_index,
+    lang_id, data, (uint16_t)length, 1000);
+}
+#endif
 
 using content::BrowserThread;
 
