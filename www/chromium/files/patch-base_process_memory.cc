--- base/process/memory.cc.orig	2022-02-07 13:39:41 UTC
+++ base/process/memory.cc
@@ -63,14 +63,16 @@ NOINLINE void OnNoMemoryInternal(size_t size) {
 
 }  // namespace internal
 
+#if !defined(OS_BSD)
 void TerminateBecauseOutOfMemory(size_t size) {
   internal::OnNoMemoryInternal(size);
 }
+#endif
 
 // Defined in memory_mac.mm for macOS + use_allocator="none".  In case of
 // USE_PARTITION_ALLOC_AS_MALLOC, no need to route the call to the system
 // default calloc of macOS.
-#if !defined(OS_APPLE) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if (!defined(OS_APPLE) && !defined(OS_BSD)) || BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
