--- ./chrome/browser/extensions/api/serial/serial_api.cc.orig	2014-04-30 22:42:00.000000000 +0200
+++ ./chrome/browser/extensions/api/serial/serial_api.cc	2014-05-04 14:38:46.000000000 +0200
@@ -84,7 +84,7 @@
 
 void SerialGetDevicesFunction::Work() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
-
+#if !defined(OS_FREEBSD) //XXX(rene) quick hack
   device::SerialDeviceInfoList devices;
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
@@ -106,6 +106,7 @@
   }
 
   results_ = serial::GetDevices::Results::Create(out_devices);
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {}
