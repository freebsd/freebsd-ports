--- device/usb/usb_service_impl.cc.orig	2015-07-15 16:30:04.000000000 -0400
+++ device/usb/usb_service_impl.cc	2015-07-22 20:14:21.946835000 -0400
@@ -17,7 +17,11 @@
 #include "base/thread_task_runner_handle.h"
 #include "components/device_event_log/device_event_log.h"
 #include "device/usb/usb_error.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 #if defined(OS_WIN)
 #include <setupapi.h>
@@ -294,6 +298,7 @@
       weak_factory_(this) {
   base::MessageLoop::current()->AddDestructionObserver(this);
 
+#if !defined(OS_FREEBSD)
   int rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -321,14 +326,16 @@
     }
 #endif  // OS_WIN
   }
+#endif // !OS_FREEBSD
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
   base::MessageLoop::current()->RemoveDestructionObserver(this);
-
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_) {
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
   }
+#endif // !OS_FREEBSD
   for (const auto& map_entry : devices_) {
     map_entry.second->OnDisconnect();
   }
@@ -566,6 +573,7 @@
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
@@ -603,6 +611,7 @@
 
   return 0;
 }
+#endif // !OS_FREEBSD
 
 void UsbServiceImpl::OnPlatformDeviceAdded(PlatformUsbDevice platform_device) {
   DCHECK(CalledOnValidThread());
