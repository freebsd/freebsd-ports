The hotplug API is not available on FreeBSD <= 10.3.

The API was added in base r302080, so it is part of FreeBSD 11.0+. It was
MFC'ed to stable/10 in r302275, which is between __FreeBSD_version's 1003505
(r302228) and 1003506 (r304611).
--- src/3rdparty/chromium/device/usb/usb_service_impl.cc.orig	2017-04-20 16:14:07 UTC
+++ src/3rdparty/chromium/device/usb/usb_service_impl.cc
@@ -482,6 +482,7 @@ UsbServiceImpl::UsbServiceImpl(
   }
   context_ = new UsbContext(platform_context);
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
   rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -492,6 +493,7 @@ UsbServiceImpl::UsbServiceImpl(
   if (rv == LIBUSB_SUCCESS) {
     hotplug_enabled_ = true;
   }
+#endif
 
   RefreshDevices();
 #if defined(OS_WIN)
@@ -504,7 +506,9 @@ UsbServiceImpl::UsbServiceImpl(
 
 UsbServiceImpl::~UsbServiceImpl() {
   if (hotplug_enabled_) {
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
+#endif
   }
   for (const auto& map_entry : devices_) {
     map_entry.second->OnDisconnect();
@@ -744,6 +748,7 @@ void UsbServiceImpl::RemoveDevice(scoped
 }
 
 // static
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
                                                 libusb_hotplug_event event,
@@ -799,5 +804,6 @@ void UsbServiceImpl::OnPlatformDeviceRem
   }
   libusb_unref_device(platform_device);
 }
+#endif  // defined(__FreeBSD_version) && __FreeBSD_version >= 1003506
 
 }  // namespace device
