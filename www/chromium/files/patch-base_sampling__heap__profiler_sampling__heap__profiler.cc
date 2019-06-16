--- base/sampling_heap_profiler/sampling_heap_profiler.cc.orig	2019-06-13 09:11:51.000000000 +0200
+++ base/sampling_heap_profiler/sampling_heap_profiler.cc	2019-06-14 21:28:04.089347000 +0200
@@ -30,6 +30,10 @@
 #include <sys/prctl.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(OS_ANDROID) && BUILDFLAG(CAN_UNWIND_WITH_CFI_TABLE) && \
     defined(OFFICIAL_BUILD)
 #include "base/trace_event/cfi_backtrace_android.h"
@@ -65,6 +69,10 @@
 #elif defined(OS_MACOSX)
   int err = pthread_getname_np(pthread_self(), name, kBufferLen);
   if (err == 0 && *name != '\0')
+    return strdup(name);
+#elif defined(OS_BSD) && defined(HAVE_PTHREAD_GET_NAME_NP)
+  pthread_get_name_np(pthread_self(), name, kBufferLen);
+  if (*name != '\0')
     return strdup(name);
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
 
