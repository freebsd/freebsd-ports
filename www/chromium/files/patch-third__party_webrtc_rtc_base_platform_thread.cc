--- third_party/webrtc/rtc_base/platform_thread.cc.orig	2017-12-15 02:05:40.000000000 +0100
+++ third_party/webrtc/rtc_base/platform_thread.cc	2017-12-24 19:19:48.387841000 +0100
@@ -16,7 +16,9 @@
 #include "rtc_base/trace_event.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -31,8 +33,10 @@
   ret = pthread_mach_thread_np(pthread_self());
 #elif defined(WEBRTC_ANDROID)
   ret = gettid();
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) && !defined(__FreeBSD__)
   ret =  syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+  ret = reinterpret_cast<uint64_t>(pthread_self());
 #else
   // Default implementation for nacl and solaris.
   ret = reinterpret_cast<pid_t>(pthread_self());
@@ -59,6 +63,7 @@
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__FreeBSD__)
 #if defined(WEBRTC_WIN)
   struct {
     DWORD dwType;
@@ -76,6 +81,7 @@
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
