--- third_party/webrtc/rtc_base/platform_thread.cc.orig	2018-03-20 23:06:54.000000000 +0100
+++ third_party/webrtc/rtc_base/platform_thread.cc	2018-03-24 18:50:14.671302000 +0100
@@ -16,7 +16,9 @@
 #include "rtc_base/trace_event.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -37,8 +39,10 @@
   ret = gettid();
 #elif defined(WEBRTC_FUCHSIA)
   ret = zx_thread_self();
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) && !defined(__FreeBSD__)
   ret = syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+  ret = reinterpret_cast<uint64_t>(pthread_self());
 #else
   // Default implementation for nacl and solaris.
   ret = reinterpret_cast<pid_t>(pthread_self());
@@ -65,6 +69,7 @@
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__FreeBSD__)
 #if defined(WEBRTC_WIN)
   struct {
     DWORD dwType;
@@ -82,6 +87,7 @@
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
