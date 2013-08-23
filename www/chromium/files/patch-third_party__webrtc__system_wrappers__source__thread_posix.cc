--- third_party/webrtc/system_wrappers/source/thread_posix.cc.orig	2013-08-09 22:21:35.000000000 +0300
+++ third_party/webrtc/system_wrappers/source/thread_posix.cc	2013-08-16 23:34:09.000000000 +0300
@@ -51,9 +51,11 @@
 #include <string.h>  // strncpy
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
@@ -136,12 +138,12 @@
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
 
@@ -171,7 +173,8 @@
   delete crit_state_;
 }
 
-#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC)
+#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC) && \
+                      !defined(WEBRTC_BSD)
 
 bool ThreadPosix::Start(unsigned int& thread_id)
 {
@@ -235,7 +238,8 @@
 
 // CPU_ZERO and CPU_SET are not available in NDK r7, so disable
 // SetAffinity on Android for now.
-#if (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)))
+#if (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID) && \
+    !defined(WEBRTC_BSD)))
 bool ThreadPosix::SetAffinity(const int* processor_numbers,
                               const unsigned int amount_of_processors) {
   if (!processor_numbers || (amount_of_processors == 0)) {
@@ -317,7 +321,7 @@
   event_->Set();
 
   if (set_thread_name_) {
-#ifdef WEBRTC_LINUX
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
     prctl(PR_SET_NAME, (unsigned long)name_, 0, 0, 0);
 #endif
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
