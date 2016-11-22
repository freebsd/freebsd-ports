--- extensions/browser/api/serial/serial_api.cc.orig	2016-08-12 04:05:07.712438000 +0300
+++ extensions/browser/api/serial/serial_api.cc	2016-08-12 04:06:56.974572000 +0300
@@ -85,12 +85,13 @@
 
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
-
+#if !defined(OS_BSD)
   std::unique_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       devices.To<std::vector<serial::DeviceInfo>>());
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
