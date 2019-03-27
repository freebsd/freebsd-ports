--- src/3rdparty/chromium/third_party/blink/renderer/platform/heap/stack_frame_depth.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/heap/stack_frame_depth.cc
@@ -15,6 +15,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace blink {
 
 static const char* g_avoid_optimization = nullptr;
