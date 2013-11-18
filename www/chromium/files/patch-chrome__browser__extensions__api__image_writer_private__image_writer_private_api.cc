--- chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc.orig	2013-11-16 01:16:39.000000000 +0100
+++ chrome/browser/extensions/api/image_writer_private/image_writer_private_api.cc	2013-11-17 23:32:59.000000000 +0100
@@ -149,10 +149,12 @@
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
 
