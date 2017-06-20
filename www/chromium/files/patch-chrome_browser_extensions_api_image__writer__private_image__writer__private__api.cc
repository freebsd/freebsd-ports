--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -167,10 +167,12 @@ ImageWriterPrivateListRemovableStorageDevicesFunction:
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
 
