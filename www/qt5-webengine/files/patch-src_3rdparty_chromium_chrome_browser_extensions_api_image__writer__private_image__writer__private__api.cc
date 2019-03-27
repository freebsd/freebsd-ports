--- src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc
@@ -137,9 +137,11 @@ ImageWriterPrivateListRemovableStorageDevicesFunction:
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunAsync() {
+#if !defined(OS_FREEBSD)
   RemovableStorageProvider::GetAllDevices(base::BindOnce(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
