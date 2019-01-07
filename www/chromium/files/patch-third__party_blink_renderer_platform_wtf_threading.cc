--- third_party/blink/renderer/platform/wtf/threading.cc.orig	2018-12-15 18:39:29.942481000 +0100
+++ third_party/blink/renderer/platform/wtf/threading.cc	2018-12-15 18:41:49.286222000 +0100
@@ -17,12 +17,16 @@
 #error Blink does not support threading on your platform.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/syscall.h>
 #elif defined(OS_ANDROID)
 #include <sys/types.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 // Current thread identity
@@ -38,6 +42,8 @@
   return syscall(__NR_gettid);
 #elif defined(OS_ANDROID)
   return gettid();
+#elif defined(OS_BSD)
+  return pthread_getthreadid_np();
 #else
   return reinterpret_cast<uintptr_t>(pthread_self());
 #endif
