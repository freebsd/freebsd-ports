--- ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2014-04-24 22:35:08.000000000 +0200
+++ ./chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2014-04-24 23:23:42.000000000 +0200
@@ -166,10 +166,12 @@
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
 
