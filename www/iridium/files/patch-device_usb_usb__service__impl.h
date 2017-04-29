--- device/usb/usb_service_impl.h.orig	2017-04-19 19:06:34 UTC
+++ device/usb/usb_service_impl.h
@@ -15,7 +15,13 @@
 #include "build/build_config.h"
 #include "device/usb/usb_context.h"
 #include "device/usb/usb_device_impl.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
+
 
 #if defined(OS_WIN)
 #include "base/scoped_observer.h"
@@ -73,11 +79,13 @@ class UsbServiceImpl :
                  scoped_refptr<UsbDeviceImpl> device);
   void RemoveDevice(scoped_refptr<UsbDeviceImpl> device);
 
+#if !defined(OS_FREEBSD)
   // Handle hotplug events from libusb.
   static int LIBUSB_CALL HotplugCallback(libusb_context* context,
                                          PlatformUsbDevice device,
                                          libusb_hotplug_event event,
                                          void* user_data);
+#endif
   // These functions release a reference to the provided platform device.
   void OnPlatformDeviceAdded(PlatformUsbDevice platform_device);
   void OnPlatformDeviceRemoved(PlatformUsbDevice platform_device);
@@ -94,7 +102,9 @@ class UsbServiceImpl :
   // connected instead of only when a full enumeration is requested.
   // TODO(reillyg): Support this on all platforms. crbug.com/411715
   bool hotplug_enabled_ = false;
+#if !defined(OS_FREEBSD)
   libusb_hotplug_callback_handle hotplug_handle_;
+#endif
 
   // Enumeration callbacks are queued until an enumeration completes.
   bool enumeration_ready_ = false;
