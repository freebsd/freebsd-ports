--- ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-04-30 22:41:59.000000000 +0200
+++ ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2014-05-04 14:38:46.000000000 +0200
@@ -167,10 +167,12 @@
 }
 
 bool ImageWriterPrivateListRemovableStorageDevicesFunction::RunImpl() {
+#if !defined(OS_FREEBSD)
   RemovableStorageProvider::GetAllDevices(
     base::Bind(
       &ImageWriterPrivateListRemovableStorageDevicesFunction::OnDeviceListReady,
       this));
+#endif
   return true;
 }
 
