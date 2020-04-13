--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -33,6 +33,9 @@
 #include <sys/types.h>
 #include <unistd.h>
 #endif
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#include <pthread_np.h>
+#endif
 
 namespace perfetto {
 namespace base {
@@ -41,6 +44,11 @@ namespace base {
 using PlatformThreadID = pid_t;
 inline PlatformThreadID GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+using PlatformThreadID = int;
+inline PlatformThreadID GetThreadId() {
+  return pthread_getthreadid_np();
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadID = pid_t;
