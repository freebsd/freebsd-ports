--- src/3rdparty/chromium/device/usb/usb_service_impl.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/usb/usb_service_impl.cc
@@ -26,7 +26,11 @@
 #include "device/usb/usb_error.h"
 #include "device/usb/webusb_descriptors.h"
 #include "net/base/io_buffer.h"
-#include "third_party/libusb/src/libusb/libusb.h"
+#if defined(OS_FREEBSD)
+#  include <libusb.h>
+#else
+#  include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_WIN)
 #include <setupapi.h>
@@ -213,6 +217,7 @@ UsbServiceImpl::UsbServiceImpl(
   }
   context_ = new UsbContext(platform_context);
 
+#if !defined(OS_FREEBSD)
   rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -225,6 +230,8 @@ UsbServiceImpl::UsbServiceImpl(
   }
 
   RefreshDevices();
+#endif // !defined(OS_FREEBSD)
+
 #if defined(OS_WIN)
   DeviceMonitorWin* device_monitor = DeviceMonitorWin::GetForAllInterfaces();
   if (device_monitor) {
@@ -234,8 +241,10 @@ UsbServiceImpl::UsbServiceImpl(
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_)
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
+#endif // !defined(OS_FREEBSD)
   for (auto* platform_device : ignored_devices_)
     libusb_unref_device(platform_device);
 }
@@ -477,6 +486,7 @@ void UsbServiceImpl::RemoveDevice(scoped
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
@@ -514,6 +524,7 @@ int LIBUSB_CALL UsbServiceImpl::HotplugC
 
   return 0;
 }
+#endif // !defined(OS_FREEBSD)
 
 void UsbServiceImpl::OnPlatformDeviceAdded(PlatformUsbDevice platform_device) {
   DCHECK(CalledOnValidThread());
