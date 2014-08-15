--- ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-08-12 21:01:44.000000000 +0200
+++ ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2014-08-13 09:56:56.000000000 +0200
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
 
