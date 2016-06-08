--- device/serial/serial_service_impl.cc.orig	2016-05-11 19:02:22 UTC
+++ device/serial/serial_service_impl.cc
@@ -74,9 +74,14 @@ void SerialServiceImpl::Connect(
 }
 
 SerialDeviceEnumerator* SerialServiceImpl::GetDeviceEnumerator() {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return NULL;
+#else
   if (!device_enumerator_)
     device_enumerator_ = SerialDeviceEnumerator::Create();
   return device_enumerator_.get();
+#endif
 }
 
 bool SerialServiceImpl::IsValidPath(const mojo::String& path) {
