--- base/process/memory.cc.orig	2017-04-19 19:06:28 UTC
+++ base/process/memory.cc
@@ -31,7 +31,7 @@ void TerminateBecauseOutOfMemory(size_t 
 #endif
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
