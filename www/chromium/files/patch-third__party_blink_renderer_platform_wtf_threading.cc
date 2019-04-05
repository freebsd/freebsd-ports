--- third_party/blink/renderer/platform/wtf/threading.cc.orig	2019-03-11 22:01:04 UTC
+++ third_party/blink/renderer/platform/wtf/threading.cc
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
@@ -38,6 +42,8 @@ ThreadIdentifier CurrentThreadSyscall() {
   return syscall(__NR_gettid);
 #elif defined(OS_ANDROID)
   return gettid();
+#elif defined(OS_BSD)
+  return pthread_getthreadid_np();
 #else
   return reinterpret_cast<uintptr_t>(pthread_self());
 #endif
