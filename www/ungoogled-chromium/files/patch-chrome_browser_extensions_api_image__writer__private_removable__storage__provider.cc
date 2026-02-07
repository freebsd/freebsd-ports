--- chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/extensions/api/image_writer_private/removable_storage_provider.cc
@@ -9,6 +9,8 @@
 #include "base/task/thread_pool.h"
 #include "content/public/browser/browser_thread.h"
 
+#include "base/notimplemented.h"
+
 namespace extensions {
 
 // A device list to be returned when testing.
@@ -20,6 +22,7 @@ static base::LazyInstance<scoped_refptr<StorageDeviceL
 
 void RemovableStorageProvider::GetAllDevices(DeviceListReadyCallback callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
+#if !BUILDFLAG(IS_BSD)
   if (g_test_device_list.Get().get() != nullptr) {
     base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
         FROM_HERE,
@@ -33,6 +36,9 @@ void RemovableStorageProvider::GetAllDevices(DeviceLis
        base::TaskShutdownBehavior::SKIP_ON_SHUTDOWN},
       base::BindOnce(&RemovableStorageProvider::PopulateDeviceList),
       std::move(callback));
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 // static
