--- third_party/WebKit/Source/platform/wtf/StackUtil.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/StackUtil.cpp	2017-09-06 22:25:12.873520000 +0200
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
