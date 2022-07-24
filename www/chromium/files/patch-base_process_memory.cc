--- base/process/memory.cc.orig	2022-07-22 17:30:31 UTC
+++ base/process/memory.cc
@@ -29,7 +29,7 @@ namespace base {
 // Defined in memory_mac.mm for macOS + use_allocator="none".  In case of
 // USE_PARTITION_ALLOC_AS_MALLOC, no need to route the call to the system
 // default calloc of macOS.
-#if !BUILDFLAG(IS_APPLE) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if (!BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
