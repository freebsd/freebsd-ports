--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-10-10 08:54:10 UTC
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -167,10 +167,12 @@
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunAsync() {
+#if !defined(OS_FREEBSD)
   RemovableStorageProvider::GetAllDevices(
     base::Bind(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
