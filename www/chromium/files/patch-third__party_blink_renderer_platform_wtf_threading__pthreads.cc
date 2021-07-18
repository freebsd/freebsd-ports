--- third_party/blink/renderer/platform/wtf/threading_pthreads.cc.orig	2021-04-14 18:41:11 UTC
+++ third_party/blink/renderer/platform/wtf/threading_pthreads.cc
@@ -50,12 +50,17 @@
 #include <objc/objc-auto.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/syscall.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <unistd.h>
+#endif
+
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
 #endif
 
 namespace WTF {
