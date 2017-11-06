--- src/3rdparty/chromium/third_party/webrtc/base/platform_thread.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/platform_thread.cc
@@ -12,6 +12,8 @@
 
 #include "webrtc/base/checks.h"
 
+#include <pthread_np.h>
+
 #if defined(WEBRTC_LINUX)
 #include <sys/prctl.h>
 #include <sys/syscall.h>
@@ -30,6 +32,8 @@ PlatformThreadId CurrentThreadId() {
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
   ret = gettid();
+#elif defined(BSD)
+  ret = pthread_getthreadid_np();
 #else
   // Default implementation for nacl and solaris.
   ret = reinterpret_cast<pid_t>(pthread_self());
@@ -73,6 +77,8 @@ void SetCurrentThreadName(const char* na
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#elif defined(BSD)
+  pthread_set_name_np(pthread_self(), name);
 #endif
 }
 
