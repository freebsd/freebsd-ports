--- device/serial/serial_service_impl.cc.orig	2015-01-21 20:05:43 UTC
+++ device/serial/serial_service_impl.cc
@@ -72,9 +72,14 @@
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
