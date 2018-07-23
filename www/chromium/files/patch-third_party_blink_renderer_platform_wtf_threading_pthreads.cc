--- third_party/blink/renderer/platform/wtf/threading_pthreads.cc.orig	2018-07-19 20:19:23.794139000 +0200
+++ third_party/blink/renderer/platform/wtf/threading_pthreads.cc	2018-07-19 20:21:15.447060000 +0200
@@ -51,14 +51,19 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/syscall.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <unistd.h>
 #endif
 
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 namespace internal {
@@ -70,6 +75,8 @@
   return syscall(__NR_gettid);
 #elif defined(OS_ANDROID)
   return gettid();
+#elif defined(OS_BSD)
+  return pthread_getthreadid_np();
 #else
   return reinterpret_cast<uintptr_t>(pthread_self());
 #endif
