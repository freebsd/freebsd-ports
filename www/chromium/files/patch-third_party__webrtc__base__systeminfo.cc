--- third_party/webrtc/base/systeminfo.cc.orig	2014-10-02 17:40:33 UTC
+++ third_party/webrtc/base/systeminfo.cc
@@ -19,8 +19,12 @@
 #elif defined(WEBRTC_MAC) && !defined(WEBRTC_IOS)
 #include <ApplicationServices/ApplicationServices.h>
 #include <CoreServices/CoreServices.h>
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <unistd.h>
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #endif
 #if defined(WEBRTC_MAC)
 #include <sys/sysctl.h>
@@ -31,7 +35,7 @@
 #include "webrtc/base/win32.h"
 #elif defined(WEBRTC_MAC) && !defined(WEBRTC_IOS)
 #include "webrtc/base/macconversion.h"
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRT_BSD)
 #include "webrtc/base/linux.h"
 #endif
 #include "webrtc/base/common.h"
@@ -168,6 +172,17 @@
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
 #else  // WEBRTC_LINUX
   ProcCpuInfo proc_info;
   if (proc_info.LoadFromSystem()) {
