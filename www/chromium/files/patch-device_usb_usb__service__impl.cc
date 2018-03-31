--- device/usb/usb_service_impl.cc.orig	2018-03-20 23:05:25.000000000 +0100
+++ device/usb/usb_service_impl.cc	2018-03-24 17:34:53.453193000 +0100
@@ -27,7 +27,11 @@
 #include "device/usb/usb_device_handle.h"
 #include "device/usb/usb_error.h"
 #include "device/usb/webusb_descriptors.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_WIN)
 #define INITGUID
@@ -227,8 +231,10 @@
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_)
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
+#endif // !defined(OS_FREEBSD)
   for (auto* platform_device : ignored_devices_)
     libusb_unref_device(platform_device);
 }
@@ -285,6 +291,7 @@
 
   context_ = std::move(context);
 
+#if !defined(OS_FREEBSD)
   int rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -297,6 +304,7 @@
 
   // This will call any enumeration callbacks queued while initializing.
   RefreshDevices();
+#endif // !defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
   DeviceMonitorWin* device_monitor = DeviceMonitorWin::GetForAllInterfaces();
@@ -496,6 +504,7 @@
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
@@ -526,6 +535,7 @@
 
   return 0;
 }
+#endif // !defined(OS_FREEBSD)
 
 void UsbServiceImpl::OnPlatformDeviceAdded(PlatformUsbDevice platform_device) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
