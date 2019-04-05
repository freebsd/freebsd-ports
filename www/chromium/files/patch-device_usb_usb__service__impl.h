--- device/usb/usb_service_impl.h.orig	2019-03-11 22:00:58 UTC
+++ device/usb/usb_service_impl.h
@@ -73,11 +73,13 @@ class UsbServiceImpl :
                  scoped_refptr<UsbDeviceImpl> device);
   void RemoveDevice(scoped_refptr<UsbDeviceImpl> device);
 
+#if !defined(OS_FREEBSD)
   // Handle hotplug events from libusb.
   static int LIBUSB_CALL HotplugCallback(libusb_context* context,
                                          libusb_device* device,
                                          libusb_hotplug_event event,
                                          void* user_data);
+#endif
   // These functions release a reference to the provided platform device.
   void OnPlatformDeviceAdded(ScopedLibusbDeviceRef platform_device);
   void OnPlatformDeviceRemoved(ScopedLibusbDeviceRef platform_device);
@@ -97,7 +99,9 @@ class UsbServiceImpl :
   // connected instead of only when a full enumeration is requested.
   // TODO(reillyg): Support this on all platforms. crbug.com/411715
   bool hotplug_enabled_ = false;
+#if !defined(OS_FREEBSD)
   libusb_hotplug_callback_handle hotplug_handle_;
+#endif
 
   // Enumeration callbacks are queued until an enumeration completes.
   bool enumeration_ready_ = false;
