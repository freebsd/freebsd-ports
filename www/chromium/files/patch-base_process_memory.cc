--- base/process/memory.cc.orig	2017-12-15 02:04:05.000000000 +0100
+++ base/process/memory.cc	2017-12-31 09:49:46.308931000 +0100
@@ -10,7 +10,7 @@
 namespace base {
 
 // Defined in memory_win.cc for Windows.
-#if !defined(OS_WIN)
+#if !defined(OS_WIN) && !defined(OS_BSD)
 
 namespace {
 
@@ -31,7 +31,7 @@
 #endif
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
