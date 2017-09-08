--- base/process/process_metrics.h.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/process/process_metrics.h	2017-08-01 22:08:56.153263000 +0200
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
@@ -215,7 +221,7 @@
   // otherwise.
   bool GetIOCounters(IoCounters* io_counters) const;
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Returns the number of file descriptors currently open by the process, or
   // -1 on error.
   int GetOpenFdCount() const;
@@ -223,12 +229,12 @@
   // Returns the soft limit of file descriptors that can be opened by the
   // process, or -1 on error.
   int GetOpenFdSoftLimit() const;
-#endif  // defined(OS_LINUX) || defined(OS_AIX)
+#endif  // defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
  private:
 #if !defined(OS_MACOSX) || defined(OS_IOS)
@@ -304,7 +310,7 @@
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -352,7 +358,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
