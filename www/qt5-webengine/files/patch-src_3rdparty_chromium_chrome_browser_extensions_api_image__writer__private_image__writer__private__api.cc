--- src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2017-01-26 00:49:08 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
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
 
