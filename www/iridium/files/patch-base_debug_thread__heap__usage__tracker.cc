--- base/debug/thread_heap_usage_tracker.cc.orig	2017-04-19 19:06:28 UTC
+++ base/debug/thread_heap_usage_tracker.cc
@@ -16,11 +16,13 @@
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
