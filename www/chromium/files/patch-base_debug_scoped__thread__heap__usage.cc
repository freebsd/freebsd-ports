--- base/debug/scoped_thread_heap_usage.cc.orig	2016-12-12 23:57:03 UTC
+++ base/debug/scoped_thread_heap_usage.cc
@@ -14,11 +14,13 @@
 #include "base/threading/thread_local_storage.h"
 #include "build/build_config.h"
 
+#if !defined(OS_BSD)
 #if defined(OS_MACOSX) || defined(OS_IOS)
 #include <malloc/malloc.h>
 #else
 #include <malloc.h>
 #endif
+#endif
 
 namespace base {
 namespace debug {
