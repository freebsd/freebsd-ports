The hotplug API is not available on FreeBSD <= 10.3.

The API was added in base r302080, so it is part of FreeBSD 11.0+. It was
MFC'ed to stable/10 in r302275, which is between __FreeBSD_version's 1003505
(r302228) and 1003506 (r304611).
--- src/3rdparty/chromium/device/usb/usb_service_impl.h.orig	2017-04-20 16:14:03 UTC
+++ src/3rdparty/chromium/device/usb/usb_service_impl.h
@@ -72,6 +72,7 @@ class UsbServiceImpl :
   void RemoveDevice(scoped_refptr<UsbDeviceImpl> device);
 
   // Handle hotplug events from libusb.
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
   static int LIBUSB_CALL HotplugCallback(libusb_context* context,
                                          PlatformUsbDevice device,
                                          libusb_hotplug_event event,
@@ -79,6 +80,7 @@ class UsbServiceImpl :
   // These functions release a reference to the provided platform device.
   void OnPlatformDeviceAdded(PlatformUsbDevice platform_device);
   void OnPlatformDeviceRemoved(PlatformUsbDevice platform_device);
+#endif
 
   scoped_refptr<UsbContext> context_;
   scoped_refptr<base::SingleThreadTaskRunner> task_runner_;
@@ -88,7 +90,9 @@ class UsbServiceImpl :
   // connected instead of only when a full enumeration is requested.
   // TODO(reillyg): Support this on all platforms. crbug.com/411715
   bool hotplug_enabled_ = false;
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
   libusb_hotplug_callback_handle hotplug_handle_;
+#endif
 
   // Enumeration callbacks are queued until an enumeration completes.
   bool enumeration_ready_ = false;
