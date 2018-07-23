--- device/usb/usb_error.cc.orig	2018-06-13 00:10:18.000000000 +0200
+++ device/usb/usb_error.cc	2018-07-20 12:55:34.901660000 +0200
@@ -9,7 +9,7 @@
 namespace device {
 
 std::string ConvertPlatformUsbErrorToString(int errcode) {
-  return libusb_strerror(static_cast<libusb_error>(errcode));
+  return "";
 }
 
 }  // namespace device
