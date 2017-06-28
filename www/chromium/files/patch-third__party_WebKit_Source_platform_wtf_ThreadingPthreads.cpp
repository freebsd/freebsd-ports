--- third_party/WebKit/Source/platform/wtf/ThreadingPthreads.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/wtf/ThreadingPthreads.cpp
@@ -49,11 +49,15 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
 #include <sys/syscall.h>
 #endif
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(BSD)
+#include <pthread_np.h>
+#endif
+
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include <unistd.h>
 #endif
 
@@ -66,6 +70,8 @@ ThreadIdentifier CurrentThreadSyscall() {
   return pthread_mach_thread_np(pthread_self());
 #elif OS(LINUX)
   return syscall(__NR_gettid);
+#elif OS(BSD)
+  return pthread_getthreadid_np();
 #elif OS(ANDROID)
   return gettid();
 #else
