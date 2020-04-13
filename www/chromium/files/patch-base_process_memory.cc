--- base/process/memory.cc.orig	2020-03-16 18:39:41 UTC
+++ base/process/memory.cc
@@ -42,7 +42,7 @@ void OnNoMemoryInternal(size_t size) {
 }  // namespace internal
 
 // Defined in memory_win.cc for Windows.
-#if !defined(OS_WIN)
+#if !defined(OS_WIN) && !defined(OS_BSD)
 
 namespace {
 
@@ -61,7 +61,7 @@ void TerminateBecauseOutOfMemory(size_t size) {
 #endif  // !defined(OS_WIN)
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
