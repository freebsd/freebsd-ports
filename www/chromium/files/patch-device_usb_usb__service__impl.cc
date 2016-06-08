--- device/usb/usb_service_impl.cc.orig	2016-05-11 19:02:22 UTC
+++ device/usb/usb_service_impl.cc
@@ -24,7 +24,11 @@
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
@@ -292,6 +296,7 @@ UsbServiceImpl::UsbServiceImpl(
   }
   context_ = new UsbContext(platform_context);
 
+#if !defined(OS_FREEBSD)
   rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -304,6 +309,8 @@ UsbServiceImpl::UsbServiceImpl(
   }
 
   RefreshDevices();
+#endif // !defined(OS_FREEBSD)
+
 #if defined(OS_WIN)
   DeviceMonitorWin* device_monitor = DeviceMonitorWin::GetForAllInterfaces();
   if (device_monitor) {
@@ -313,9 +320,11 @@ UsbServiceImpl::UsbServiceImpl(
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_) {
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
   }
+#endif // !defined(OS_FREEBSD)
   for (const auto& map_entry : devices_) {
     map_entry.second->OnDisconnect();
   }
@@ -553,6 +562,7 @@ void UsbServiceImpl::RemoveDevice(scoped
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
@@ -590,6 +600,7 @@ int LIBUSB_CALL UsbServiceImpl::HotplugC
 
   return 0;
 }
+#endif // !defined(OS_FREEBSD)
 
 void UsbServiceImpl::OnPlatformDeviceAdded(PlatformUsbDevice platform_device) {
   DCHECK(CalledOnValidThread());
