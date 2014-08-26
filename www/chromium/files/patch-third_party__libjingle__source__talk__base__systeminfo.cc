--- ./third_party/libjingle/source/talk/base/systeminfo.cc.orig	2014-08-20 21:03:47.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/systeminfo.cc	2014-08-22 15:06:27.000000000 +0200
@@ -36,8 +36,12 @@
 #elif defined(OSX)
 #include <ApplicationServices/ApplicationServices.h>
 #include <CoreServices/CoreServices.h>
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <unistd.h>
+#if defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #endif
 #if defined(OSX) || defined(IOS)
 #include <sys/sysctl.h>
@@ -48,7 +52,7 @@
 #include "talk/base/win32.h"
 #elif defined(OSX)
 #include "talk/base/macconversion.h"
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 #endif
 #include "talk/base/common.h"
@@ -185,6 +189,17 @@
   }
 #elif defined(__native_client__)
   // TODO(ryanpetrie): Implement this via PPAPI when it's available.
+#elif defined(OS_FREEBSD)
+  void* sysctl_value;
+  size_t length = sizeof(sysctl_value);
+  if (!sysctlbyname("hw.ncpu", &sysctl_value, &length, NULL, 0)) {
+    physical_cpus_ = *static_cast<int*>(sysctl_value);
+  }
+  if (!sysctlbyname("kern.smp.cpus", &sysctl_value, &length, NULL, 0)) {
+    logical_cpus_ = *static_cast<int*>(sysctl_value);
+  }
+  // L3 / L2 cache size?
+  // CPU family/model/stepping (available in dmesg, kernel only TODO)
 #else  // LINUX || ANDROID
   ProcCpuInfo proc_info;
   if (proc_info.LoadFromSystem()) {
