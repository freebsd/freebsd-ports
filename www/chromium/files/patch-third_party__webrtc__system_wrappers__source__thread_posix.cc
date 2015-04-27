--- third_party/webrtc/system_wrappers/source/thread_posix.cc.orig	2015-04-19 17:26:21.000000000 +0200
+++ third_party/webrtc/system_wrappers/source/thread_posix.cc	2015-04-19 19:08:15.000000000 +0200
@@ -15,9 +15,11 @@
 #include <errno.h>
 #include <unistd.h>
 #ifdef WEBRTC_LINUX
+#if !defined(WEBRTC_BSD)
 #include <linux/unistd.h>
-#include <sched.h>
 #include <sys/prctl.h>
+#endif
+#include <sched.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
 #endif
@@ -138,7 +140,7 @@
   if (!name_.empty()) {
     // Setting the thread name may fail (harmlessly) if running inside a
     // sandbox. Ignore failures if they happen.
-#if defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && !defined(WEBRTC_BSD)
     prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name_.c_str()));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
     pthread_setname_np(name_.substr(0, 63).c_str());
