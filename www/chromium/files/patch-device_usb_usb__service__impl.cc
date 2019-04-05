--- device/usb/usb_service_impl.cc.orig	2019-03-11 22:00:58 UTC
+++ device/usb/usb_service_impl.cc
@@ -231,8 +231,10 @@ UsbServiceImpl::UsbServiceImpl()
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_)
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
+#endif // !defined(OS_FREEBSD)
 }
 
 void UsbServiceImpl::GetDevices(const GetDevicesCallback& callback) {
@@ -287,6 +289,7 @@ void UsbServiceImpl::OnUsbContext(scoped_refptr<UsbCon
 
   context_ = std::move(context);
 
+#if !defined(OS_FREEBSD)
   int rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -299,6 +302,7 @@ void UsbServiceImpl::OnUsbContext(scoped_refptr<UsbCon
 
   // This will call any enumeration callbacks queued while initializing.
   RefreshDevices();
+#endif // !defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
   DeviceMonitorWin* device_monitor = DeviceMonitorWin::GetForAllInterfaces();
@@ -495,6 +499,7 @@ void UsbServiceImpl::RemoveDevice(scoped_refptr<UsbDev
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 libusb_device* device_raw,
@@ -528,6 +533,7 @@ int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb
 
   return 0;
 }
+#endif // !defined(OS_FREEBSD)
 
 void UsbServiceImpl::OnPlatformDeviceAdded(
     ScopedLibusbDeviceRef platform_device) {
