--- base/process/process_metrics.h.orig	2016-05-11 19:02:11 UTC
+++ base/process/process_metrics.h
@@ -21,6 +21,13 @@
 #include "base/values.h"
 #include "build/build_config.h"
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #include "base/process/port_provider_mac.h"
@@ -314,13 +321,17 @@ BASE_EXPORT bool GetSystemMemoryInfo(Sys
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
 
