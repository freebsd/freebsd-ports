--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -167,10 +167,12 @@ ImageWriterPrivateListRemovableStorageDe
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
 
