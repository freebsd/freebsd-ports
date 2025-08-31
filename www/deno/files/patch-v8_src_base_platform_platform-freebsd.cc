--- cargo-crates/v8-135.1.0/v8/src/base/platform/platform-freebsd.cc.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/v8-135.1.0/v8/src/base/platform/platform-freebsd.cc
@@ -43,14 +43,10 @@ TimezoneCache* OS::CreateTimezoneCache() {
   return new PosixDefaultTimezoneCache();
 }
 
-static unsigned StringToLong(char* buffer) {
-  return static_cast<unsigned>(strtol(buffer, nullptr, 16));
-}
-
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
   std::vector<SharedLibraryAddress> result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
-  size_t miblen = sizeof(mib) / sizeof(mib[0]);
+  unsigned int miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
   if (sysctl(mib, miblen, nullptr, &buffer_size, nullptr, 0) == 0) {
     // Overallocate the buffer by 1/3 to account for concurrent
@@ -82,8 +78,13 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
+#if defined(__arm__) || defined(__i386__) || defined(OS_FREEBSD)
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
+#else
               lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
               reinterpret_cast<uintptr_t>(map->kve_end)));
+#endif
         }
 
         start += ssize;
