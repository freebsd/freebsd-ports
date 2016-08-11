--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -166,10 +166,12 @@ ImageWriterPrivateListRemovableStorageDe
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
 
