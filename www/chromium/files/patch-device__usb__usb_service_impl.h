--- device/usb/usb_service_impl.h.orig	2015-04-19 16:22:47.000000000 +0200
+++ device/usb/usb_service_impl.h	2015-04-19 21:10:55.000000000 +0200
@@ -10,7 +10,13 @@
 #include "base/single_thread_task_runner.h"
 #include "device/usb/usb_context.h"
 #include "device/usb/usb_device_impl.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
+
 
 namespace device {
 
@@ -38,11 +44,13 @@
   // Adds a new UsbDevice to the devices_ map based on the given libusb device.
   scoped_refptr<UsbDeviceImpl> AddDevice(PlatformUsbDevice platform_device);
 
+#if !defined(OS_FREEBSD)
   // Handle hotplug events from libusb.
   static int LIBUSB_CALL HotplugCallback(libusb_context* context,
                                          PlatformUsbDevice device,
                                          libusb_hotplug_event event,
                                          void* user_data);
+#endif
   // These functions release a reference to the provided platform device.
   void OnDeviceAdded(PlatformUsbDevice platform_device);
   void OnDeviceRemoved(PlatformUsbDevice platform_device);
@@ -63,7 +71,9 @@
   // connected instead of only when a full enumeration is requested.
   // TODO(reillyg): Support this on all platforms. crbug.com/411715
   bool hotplug_enabled_;
+#if !defined(OS_FREEBSD)
   libusb_hotplug_callback_handle hotplug_handle_;
+#endif
 
   // The map from unique IDs to UsbDevices.
   typedef std::map<uint32, scoped_refptr<UsbDeviceImpl>> DeviceMap;
