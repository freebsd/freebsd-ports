--- third_party/blink/renderer/platform/heap/stack_frame_depth.cc.orig	2018-07-19 19:31:59.775056000 +0200
+++ third_party/blink/renderer/platform/heap/stack_frame_depth.cc	2018-07-19 19:32:43.812459000 +0200
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
