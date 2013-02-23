--- chrome/browser/extensions/api/system_info_storage/system_info_storage_api.cc.orig	2013-02-13 23:14:07.000000000 +0200
+++ chrome/browser/extensions/api/system_info_storage/system_info_storage_api.cc	2013-02-13 23:14:56.000000000 +0200
@@ -14,9 +14,12 @@
 }
 
 bool SystemInfoStorageGetFunction::RunImpl() {
+// Not Implemented
+#if !defined(OS_BSD)
   StorageInfoProvider::Get()->StartQueryInfo(
       base::Bind(&SystemInfoStorageGetFunction::OnGetStorageInfoCompleted,
                  this));
+#endif
   return true;
 }
 
