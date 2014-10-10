--- extensions/browser/api/serial/serial_api.cc.orig	2014-10-02 17:39:47 UTC
+++ extensions/browser/api/serial/serial_api.cc
@@ -85,11 +85,13 @@
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
 
+#if !defined(OS_FREEBSD) //XXX(rene) quick hack
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       devices.To<std::vector<linked_ptr<serial::DeviceInfo> > >());
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
