--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2020-03-16 18:42:11 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
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
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+using PlatformThreadId = pid_t;
+inline PlatformThreadId GetThreadId() {
+  return pthread_getthreadid_np();
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;
