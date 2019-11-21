--- openhantek/src/usb/uploadFirmware.cpp.orig	2019-11-21 06:06:23 UTC
+++ openhantek/src/usb/uploadFirmware.cpp
@@ -39,7 +39,9 @@ bool UploadFirmware::startUpload(USBDevice *device) {
     temp_firmware_path->open();
 
     /* We need to claim the first interface */
+#if !defined(__FreeBSD__)
     libusb_set_auto_detach_kernel_driver(handle, 1);
+#endif
     int status = libusb_claim_interface(handle, 0);
     if (status != LIBUSB_SUCCESS) {
         errorMessage = TR("libusb_claim_interface() failed: %1").arg(libusb_error_name(status));
