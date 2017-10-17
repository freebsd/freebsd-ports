--- third_party/WebKit/Source/platform/wtf/ThreadingPthreads.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/ThreadingPthreads.cpp	2017-09-06 22:33:24.096670000 +0200
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
