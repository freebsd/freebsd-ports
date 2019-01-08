--- third_party/blink/renderer/platform/wtf/threading_pthreads.cc.orig	2018-12-03 21:17:54.000000000 +0100
+++ third_party/blink/renderer/platform/wtf/threading_pthreads.cc	2018-12-15 18:34:37.670619000 +0100
@@ -52,12 +52,17 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/syscall.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <unistd.h>
+#endif
+
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
 #endif
 
 namespace WTF {
