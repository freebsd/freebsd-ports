--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -34,6 +34,7 @@ __declspec(dllimport) unsigned long __stdcall GetCurre
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <pthread.h>
 #else
 #include <pthread.h>
 #endif
@@ -45,6 +46,11 @@ namespace base {
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+using PlatformThreadId = uint64_t;
+inline PlatformThreadId GetThreadId() {
+  return reinterpret_cast<uint64_t>(pthread_self());
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;
