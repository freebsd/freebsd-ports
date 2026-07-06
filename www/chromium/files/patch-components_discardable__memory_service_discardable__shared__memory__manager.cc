--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2026-07-01 06:24:19 UTC
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -177,6 +177,8 @@ uint64_t GetDefaultMaxBytes() {
 #if BUILDFLAG(IS_ANDROID)
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t default_max_bytes = 128 * kMegabyte;
+#elif BUILDFLAG(IS_OPENBSD)
+  uint64_t default_max_bytes = 128 * kMegabyte;
 #else
   uint64_t default_max_bytes = 512 * kMegabyte;
 #endif
