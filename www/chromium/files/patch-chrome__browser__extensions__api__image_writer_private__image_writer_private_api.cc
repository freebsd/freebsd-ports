--- ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-08-20 21:01:58.000000000 +0200
+++ ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2014-08-22 15:06:24.000000000 +0200
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
 
