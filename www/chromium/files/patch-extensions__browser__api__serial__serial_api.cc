--- extensions/browser/api/serial/serial_api.cc.orig	2016-03-04 22:52:57.757575528 +0100
+++ extensions/browser/api/serial/serial_api.cc	2016-03-04 22:52:30.452574585 +0100
@@ -87,7 +87,8 @@
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
 
 // TODO(moshayedi): crbug.com/549257. Add USB support for Aura on Android.
-#if !defined(OS_ANDROID)
+// XXX also, rene's quick hack on FreeBSD
+#if !defined(OS_ANDROID) && !defined(OS_FREEBSD)
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
