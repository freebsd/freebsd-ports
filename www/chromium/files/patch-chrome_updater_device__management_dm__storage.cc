--- chrome/updater/device_management/dm_storage.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/updater/device_management/dm_storage.cc
@@ -69,7 +69,7 @@ bool DeleteObsoletePolicies(const base::FilePath& cach
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // crbug.com/1276162 - implement.
 DMStorage::DMStorage(const base::FilePath& policy_cache_root)
     : policy_cache_root_(policy_cache_root) {
