--- device/usb/usb_service_impl.cc.orig	2015-04-19 21:12:40.000000000 +0200
+++ device/usb/usb_service_impl.cc	2015-04-19 21:16:15.000000000 +0200
@@ -113,6 +113,7 @@
       hotplug_enabled_(false),
       weak_factory_(this) {
   task_runner_ = base::ThreadTaskRunnerHandle::Get();
+#if !defined(OS_FREEBSD)
   int rv = libusb_hotplug_register_callback(
       context_->context(),
       static_cast<libusb_hotplug_event>(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
@@ -130,12 +131,15 @@
                                          base::Unretained(ui_thread_helper_)));
 #endif  // OS_WIN
   }
+#endif // !OS_FREEBSD
 }
 
 UsbServiceImpl::~UsbServiceImpl() {
+#if !defined(OS_FREEBSD)
   if (hotplug_enabled_) {
     libusb_hotplug_deregister_callback(context_->context(), hotplug_handle_);
   }
+#endif // !OS_FREEBSD
 #if defined(OS_WIN)
   if (ui_thread_helper_) {
     ui_task_runner_->DeleteSoon(FROM_HERE, ui_thread_helper_);
@@ -219,6 +223,7 @@
   }
 }
 
+#if !defined(OS_FREEBSD)
 // static
 int LIBUSB_CALL UsbServiceImpl::HotplugCallback(libusb_context* context,
                                                 PlatformUsbDevice device,
@@ -256,6 +261,7 @@
 
   return 0;
 }
+#endif // !OS_FREEBSD
 
 void UsbServiceImpl::OnDeviceAdded(PlatformUsbDevice platform_device) {
   DCHECK(CalledOnValidThread());
