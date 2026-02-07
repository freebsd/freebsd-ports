--- src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -20,6 +20,7 @@ void RemovableStorageProvider::GetAllDevices(DeviceLis
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !BUILDFLAG(IS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
         FROM_HERE,
@@ -33,6 +34,9 @@ void RemovableStorageProvider::GetAllDevices(DeviceLis
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
