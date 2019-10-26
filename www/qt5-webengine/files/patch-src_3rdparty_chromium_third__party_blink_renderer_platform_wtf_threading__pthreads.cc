--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/threading_pthreads.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/threading_pthreads.cc
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
