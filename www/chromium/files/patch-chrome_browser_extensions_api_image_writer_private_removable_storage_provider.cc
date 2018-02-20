--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2018-01-03 17:00:05.332673000 +0100
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc	2018-01-03 17:01:00.459066000 +0100
@@ -20,6 +20,7 @@
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !defined(OS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::ThreadTaskRunnerHandle::Get()->PostTask(
         FROM_HERE,
@@ -33,6 +34,9 @@
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
