--- device/usb/usb_service_impl.h.orig	2018-06-13 00:10:18.000000000 +0200
+++ device/usb/usb_service_impl.h	2018-07-20 12:47:42.413625000 +0200
@@ -73,11 +73,13 @@
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
@@ -95,7 +97,9 @@
   // connected instead of only when a full enumeration is requested.
   // TODO(reillyg): Support this on all platforms. crbug.com/411715
   bool hotplug_enabled_ = false;
+#if !defined(OS_FREEBSD)
   libusb_hotplug_callback_handle hotplug_handle_;
+#endif
 
   // Enumeration callbacks are queued until an enumeration completes.
   bool enumeration_ready_ = false;
