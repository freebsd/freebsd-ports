--- third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/heap/StackFrameDepth.cpp	2017-09-06 22:02:32.472630000 +0200
@@ -15,6 +15,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace blink {
 
 static const char* g_avoid_optimization = nullptr;
