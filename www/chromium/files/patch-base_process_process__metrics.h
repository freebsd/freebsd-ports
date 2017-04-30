--- base/process/process_metrics.h.orig	2017-04-19 19:06:28 UTC
+++ base/process/process_metrics.h
@@ -22,6 +22,12 @@
 #include "base/values.h"
 #include "build/build_config.h"
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #include "base/process/port_provider_mac.h"
@@ -329,13 +335,17 @@ BASE_EXPORT bool GetSystemMemoryInfo(Sys
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
 BASE_EXPORT int ParseProcStatCPU(const std::string& input);
+#endif
 
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 // Get the number of threads of |process| as available in /proc/<pid>/stat.
 // This should be used with care as no synchronization with running threads is
 // done. This is mostly useful to guarantee being single-threaded.
 // Returns 0 on failure.
 BASE_EXPORT int GetNumberOfThreads(ProcessHandle process);
+#endif
 
+#if defined(OS_LINUX) || defined(OS_ANDROID)
 // /proc/self/exe refers to the current executable.
 BASE_EXPORT extern const char kProcSelfExe[];
 
