--- chrome/browser/extensions/api/api_resource_controller.cc.orig	2012-07-11 20:11:23.658275053 +0300
+++ chrome/browser/extensions/api/api_resource_controller.cc	2012-07-11 20:42:41.301362312 +0300
@@ -5,7 +5,9 @@
 #include "chrome/browser/extensions/api/api_resource_controller.h"
 #include "chrome/browser/extensions/api/serial/serial_connection.h"
 #include "chrome/browser/extensions/api/socket/socket.h"
+#if !defined(OS_FREEBSD)
 #include "chrome/browser/extensions/api/usb/usb_device_resource.h"
+#endif
 
 namespace extensions {
 
@@ -80,10 +82,12 @@
       GetAPIResource(APIResource::SerialConnectionResource, api_resource_id));
 }
 
+#if !defined(OS_FREEBSD)
 UsbDeviceResource* APIResourceController::GetUsbDeviceResource(
     int api_resource_id) const {
   return static_cast<UsbDeviceResource*>(GetAPIResource(
       APIResource::UsbDeviceResource, api_resource_id));
 }
+#endif
 
 }  // namespace extensions
