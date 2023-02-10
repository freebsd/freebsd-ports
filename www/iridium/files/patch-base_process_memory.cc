--- base/process/memory.cc.orig	2023-01-17 19:19:00 UTC
+++ base/process/memory.cc
@@ -28,7 +28,7 @@ namespace base {
 // Defined in memory_mac.mm for macOS + use_partition_alloc_as_malloc=false.
 // In case of use_partition_alloc_as_malloc=true, no need to route the call to
 // the system default calloc of macOS.
-#if !BUILDFLAG(IS_APPLE) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if (!BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
