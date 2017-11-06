--- third_party/webrtc/rtc_base/platform_thread.cc.orig	2017-09-07 01:16:42.622602000 +0200
+++ third_party/webrtc/rtc_base/platform_thread.cc	2017-09-07 01:29:26.664318000 +0200
@@ -15,11 +15,18 @@
 #include "webrtc/rtc_base/timeutils.h"
 #include "webrtc/rtc_base/trace_event.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
 
+#if defined(WEBRTC_BSD)
+#include <pthread.h>
+#include <pthread_np.h>
+#include <sys/syscall.h>
+#include <sys/thr.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -29,6 +36,8 @@
 #elif defined(WEBRTC_POSIX)
 #if defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   ret = pthread_mach_thread_np(pthread_self());
+#elif defined(WEBRTC_BSD)
+  ret = reinterpret_cast<int>(pthread_getthreadid_np());
 #elif defined(WEBRTC_LINUX)
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
@@ -72,7 +81,9 @@
                      reinterpret_cast<ULONG_PTR*>(&threadname_info));
   } __except (EXCEPTION_EXECUTE_HANDLER) {
   }
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#elif defined(WEBRTC_BSD)
+  pthread_set_name_np(pthread_self(), name);
+#elif (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && !defined(WEBRTC_BSD)
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
