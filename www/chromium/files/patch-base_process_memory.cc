--- base/process/memory.cc.orig	2020-11-13 06:36:34 UTC
+++ base/process/memory.cc
@@ -55,7 +55,7 @@ NOINLINE void OnNoMemoryInternal(size_t size) {
 }  // namespace internal
 
 // Defined in memory_win.cc for Windows.
-#if !defined(OS_WIN)
+#if !defined(OS_WIN) && !defined(OS_BSD)
 
 namespace {
 
@@ -74,7 +74,7 @@ void TerminateBecauseOutOfMemory(size_t size) {
 #endif  // !defined(OS_WIN)
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
