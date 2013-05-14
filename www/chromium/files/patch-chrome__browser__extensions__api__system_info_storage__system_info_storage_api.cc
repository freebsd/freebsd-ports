--- chrome/browser/extensions/api/system_info_storage/system_info_storage_api.cc.orig	2013-02-13 23:14:07.000000000 +0200
+++ chrome/browser/extensions/api/system_info_storage/system_info_storage_api.cc	2013-02-13 23:14:56.000000000 +0200
@@ -14,10 +14,14 @@
 }
 
 bool SystemInfoStorageGetFunction::RunImpl() {
+#if defined(OS_BSD)
+  return false;
+#else
   StorageInfoProvider::Get()->StartQueryInfo(
       base::Bind(&SystemInfoStorageGetFunction::OnGetStorageInfoCompleted,
                  this));
   return true;
+#endif
 }
 
 void SystemInfoStorageGetFunction::OnGetStorageInfoCompleted(
 
