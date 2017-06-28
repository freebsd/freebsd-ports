--- base/process/process_metrics.h.orig	2017-06-05 19:03:00 UTC
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
@@ -205,7 +211,7 @@ class BASE_EXPORT ProcessMetrics {
   // otherwise.
   bool GetIOCounters(IoCounters* io_counters) const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the number of file descriptors currently open by the process, or
   // -1 on error.
   int GetOpenFdCount() const;
@@ -213,7 +219,7 @@ class BASE_EXPORT ProcessMetrics {
   // Returns the soft limit of file descriptors that can be opened by the
   // process, or -1 on error.
   int GetOpenFdSoftLimit() const;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
  private:
 #if !defined(OS_MACOSX) || defined(OS_IOS)
@@ -289,7 +295,7 @@ BASE_EXPORT void SetFdLimit(unsigned int max_descripto
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -383,13 +389,17 @@ BASE_EXPORT bool GetSystemMemoryInfo(SystemMemoryInfoK
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
 
