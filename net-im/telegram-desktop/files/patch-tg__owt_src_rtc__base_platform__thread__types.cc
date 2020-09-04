--- tg_owt/src/rtc_base/platform_thread_types.cc.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/src/rtc_base/platform_thread_types.cc
@@ -11,10 +11,14 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
-#include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/thr.h>
+#include <pthread_np.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -28,7 +32,13 @@ PlatformThreadId CurrentThreadId() {
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
 #elif defined(WEBRTC_LINUX)
+#if defined(__FreeBSD__)
+  long id;
+  thr_self(&id);
+  return id;
+#else
   return syscall(__NR_gettid);
+#endif
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
 #else
@@ -78,9 +88,7 @@ void SetCurrentThreadName(const char* name) {
   }
 #pragma warning(pop)
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
-  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
-#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
-  pthread_setname_np(name);
+  pthread_set_name_np(pthread_self(), name);
 #endif
 }
 
