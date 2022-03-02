--- chrome/updater/device_management/dm_storage.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/updater/device_management/dm_storage.cc
@@ -70,7 +70,7 @@ bool DeleteObsoletePolicies(const base::FilePath& cach
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // crbug.com/1276162 - implement.
 DMStorage::DMStorage(const base::FilePath& policy_cache_root)
     : policy_cache_root_(policy_cache_root) {
