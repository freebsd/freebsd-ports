--- base/sampling_heap_profiler/sampling_heap_profiler.cc.orig	2021-09-14 01:51:47 UTC
+++ base/sampling_heap_profiler/sampling_heap_profiler.cc
@@ -27,6 +27,10 @@
 #include <sys/prctl.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(OS_ANDROID) && BUILDFLAG(CAN_UNWIND_WITH_CFI_TABLE) && \
     defined(OFFICIAL_BUILD)
 #include "base/trace_event/cfi_backtrace_android.h"  // no-presubmit-check
@@ -62,6 +66,10 @@ const char* GetAndLeakThreadName() {
 #elif defined(OS_APPLE)
   int err = pthread_getname_np(pthread_self(), name, kBufferLen);
   if (err == 0 && *name != '\0')
+    return strdup(name);
+#elif defined(OS_BSD) && __FreeBSD__ >= 12
+  pthread_get_name_np(pthread_self(), name, kBufferLen);
+  if (*name != '\0')
     return strdup(name);
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
 
