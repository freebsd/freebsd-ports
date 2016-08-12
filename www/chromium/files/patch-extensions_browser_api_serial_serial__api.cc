--- extensions/browser/api/serial/serial_api.cc.orig	2016-07-22 00:06:55.000000000 -0400
+++ extensions/browser/api/serial/serial_api.cc	2016-08-03 15:23:41.022195000 -0400
@@ -86,11 +86,13 @@
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
 
+#if !defined(OS_BSD)
   std::unique_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       devices.To<std::vector<serial::DeviceInfo>>());
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
