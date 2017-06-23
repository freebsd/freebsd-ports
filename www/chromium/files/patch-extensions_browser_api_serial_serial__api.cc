--- extensions/browser/api/serial/serial_api.cc.orig	2017-06-05 19:03:07 UTC
+++ extensions/browser/api/serial/serial_api.cc
@@ -86,11 +86,13 @@ bool SerialGetDevicesFunction::Prepare() {
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
 
+#if !defined(OS_BSD)
   std::unique_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   std::vector<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       mojo::ConvertTo<std::vector<serial::DeviceInfo>>(devices));
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
