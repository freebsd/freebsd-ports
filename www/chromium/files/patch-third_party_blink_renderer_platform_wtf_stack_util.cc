--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2018-07-19 20:18:16.483555000 +0200
+++ third_party/blink/renderer/platform/wtf/stack_util.cc	2018-07-19 20:18:51.633152000 +0200
@@ -16,6 +16,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
