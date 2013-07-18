--- third_party/webrtc/system_wrappers/source/thread_posix.cc.orig	2013-07-16 17:45:33.000000000 +0300
+++ third_party/webrtc/system_wrappers/source/thread_posix.cc	2013-07-16 17:58:51.000000000 +0300
@@ -54,9 +54,13 @@
 #include <sys/types.h>
 #include <sched.h>
 #include <sys/syscall.h>
+#if defined(WEBRTC_BSD)
+#include <sys/unistd.h>
+#else
 #include <linux/unistd.h>
 #include <sys/prctl.h>
 #endif
+#endif
 
 #include "webrtc/system_wrappers/interface/critical_section_wrapper.h"
 #include "webrtc/system_wrappers/interface/event_wrapper.h"
@@ -136,12 +140,12 @@
 }
 
 uint32_t ThreadWrapper::GetThreadId() {
-#if defined(WEBRTC_ANDROID) || defined(WEBRTC_LINUX)
+#if (defined(WEBRTC_ANDROID) || defined(WEBRTC_LINUX)) && !defined(WEBRTC_BSD)
   return static_cast<uint32_t>(syscall(__NR_gettid));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   return pthread_mach_thread_np(pthread_self());
 #else
-  return reinterpret_cast<uint32_t>(pthread_self());
+  return reinterpret_cast<uint64_t>(pthread_self());
 #endif
 }
 
@@ -171,7 +175,8 @@
   delete crit_state_;
 }
 
-#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC)
+#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC) && \
+                      !defined(WEBRTC_BSD)
 
 bool ThreadPosix::Start(unsigned int& thread_id)
 {
@@ -235,7 +240,8 @@
 
 // CPU_ZERO and CPU_SET are not available in NDK r7, so disable
 // SetAffinity on Android for now.
-#if (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)))
+#if (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID) && \
+    !defined(WEBRTC_BSD)))
 bool ThreadPosix::SetAffinity(const int* processor_numbers,
                               const unsigned int amount_of_processors) {
   if (!processor_numbers || (amount_of_processors == 0)) {
@@ -317,7 +323,7 @@
   event_->Set();
 
   if (set_thread_name_) {
-#ifdef WEBRTC_LINUX
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
     prctl(PR_SET_NAME, (unsigned long)name_, 0, 0, 0);
 #endif
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
