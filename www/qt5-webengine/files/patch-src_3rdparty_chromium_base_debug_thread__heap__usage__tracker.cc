--- src/3rdparty/chromium/base/debug/thread_heap_usage_tracker.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/debug/thread_heap_usage_tracker.cc
@@ -17,10 +17,12 @@
 #include "base/threading/thread_local_storage.h"
 #include "build/build_config.h"
 
+#if !defined(OS_BSD)
 #if defined(OS_MACOSX) || defined(OS_IOS)
 #include <malloc/malloc.h>
 #else
 #include <malloc.h>
+#endif
 #endif
 
 namespace base {
