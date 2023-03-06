--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -18,6 +18,11 @@ extern "C" void* __libc_stack_end;  // NOLINT
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
