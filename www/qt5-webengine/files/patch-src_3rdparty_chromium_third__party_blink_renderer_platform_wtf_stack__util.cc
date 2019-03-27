--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc
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
