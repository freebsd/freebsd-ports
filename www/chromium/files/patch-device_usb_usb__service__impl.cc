--- device/usb/usb_service_impl.cc.orig	2019-04-30 22:22:48 UTC
+++ device/usb/usb_service_impl.cc
@@ -233,8 +233,10 @@ UsbServiceImpl::UsbServiceImpl()
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_)
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
+#endif // !defined(OS_FREEBSD)
 }
 
 void UsbServiceImpl::GetDevices(const GetDevicesCallback& callback) {
@@ -289,6 +291,7 @@ void UsbServiceImpl::OnUsbContext(scoped_refptr<UsbCon
 
   context_ = std::move(context);
 
+#if !defined(OS_FREEBSD)
   int rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -301,6 +304,7 @@ void UsbServiceImpl::OnUsbContext(scoped_refptr<UsbCon
 
   // This will call any enumeration callbacks queued while initializing.
   RefreshDevices();
+#endif // !defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
   DeviceMonitorWin* device_monitor = DeviceMonitorWin::GetForAllInterfaces();
@@ -497,6 +501,7 @@ void UsbServiceImpl::RemoveDevice(scoped_refptr<UsbDev
   device->OnDisconnect();
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 libusb_device* device_raw,
@@ -530,6 +535,7 @@ int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb
 
   return 0;
 }
+#endif // !defined(OS_FREEBSD)
 
 void UsbServiceImpl::OnPlatformDeviceAdded(
     ScopedLibusbDeviceRef platform_device) {
