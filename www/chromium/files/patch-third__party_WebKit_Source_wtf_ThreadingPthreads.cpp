--- third_party/WebKit/Source/wtf/ThreadingPthreads.cpp.orig	2016-07-20 22:03:42.000000000 +0300
+++ third_party/WebKit/Source/wtf/ThreadingPthreads.cpp	2016-08-12 11:08:14.275410000 +0300
@@ -51,11 +51,15 @@
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

@@ -97,6 +101,8 @@
     return pthread_mach_thread_np(pthread_self());
 #elif OS(LINUX)
     return syscall(__NR_gettid);
+#elif OS(BSD)
+    return pthread_getthreadid_np();
 #elif OS(ANDROID)
     return gettid();
 #else
