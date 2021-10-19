--- base/process/memory.cc.orig	2021-09-14 01:51:47 UTC
+++ base/process/memory.cc
@@ -70,7 +70,7 @@ void TerminateBecauseOutOfMemory(size_t size) {
 // Defined in memory_mac.mm for macOS + use_allocator="none".  In case of
 // USE_PARTITION_ALLOC_AS_MALLOC, no need to route the call to the system
 // default calloc of macOS.
-#if !defined(OS_APPLE) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if (!defined(OS_APPLE) && !defined(OS_BSD)) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
