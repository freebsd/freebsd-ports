--- device/usb/usb_device_handle_impl.cc.orig	2014-10-10 08:54:15 UTC
+++ device/usb/usb_device_handle_impl.cc
@@ -19,7 +19,13 @@
 #include "device/usb/usb_device_impl.h"
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
+#if defined(OS_FREEBSD)
+#include <osreldate.h>
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
@@ -105,6 +111,18 @@
 
 }  // namespace
 
+// Define for FreeBSD < 9.3, thanks to db@freebsd.org
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
+
 class UsbDeviceHandleImpl::InterfaceClaimer
     : public base::RefCountedThreadSafe<UsbDeviceHandleImpl::InterfaceClaimer> {
  public:
