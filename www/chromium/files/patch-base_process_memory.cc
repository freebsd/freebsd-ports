--- base/process/memory.cc.orig	2019-03-11 22:00:51 UTC
+++ base/process/memory.cc
@@ -10,7 +10,7 @@
 namespace base {
 
 // Defined in memory_win.cc for Windows.
-#if !defined(OS_WIN)
+#if !defined(OS_WIN) && !defined(OS_BSD)
 
 namespace {
 
@@ -31,7 +31,7 @@ void TerminateBecauseOutOfMemory(size_t size) {
 #endif
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
