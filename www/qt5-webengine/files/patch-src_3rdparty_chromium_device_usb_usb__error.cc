--- src/3rdparty/chromium/device/usb/usb_error.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/device/usb/usb_error.cc
@@ -9,7 +9,7 @@
 namespace device {
 
 std::string ConvertPlatformUsbErrorToString(int errcode) {
-  return libusb_strerror(static_cast<libusb_error>(errcode));
+  return "";
 }
 
 }  // namespace device
