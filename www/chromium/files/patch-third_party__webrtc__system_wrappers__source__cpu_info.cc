--- third_party/webrtc/system_wrappers/source/cpu_info.cc.orig	2014-10-02 17:40:34 UTC
+++ third_party/webrtc/system_wrappers/source/cpu_info.cc
@@ -12,7 +12,10 @@
 
 #if defined(_WIN32)
 #include <Windows.h>
-#elif defined(WEBRTC_MAC)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD)
+#if defined(WEBRTC_BSD)
+#include <sys/param.h>
+#endif
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #else // defined(WEBRTC_LINUX) or defined(WEBRTC_ANDROID)
@@ -34,13 +37,17 @@
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
                  "Available number of cores:%d", number_of_cores_);
 
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#elif (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && !defined(WEBRTC_BSD)
     number_of_cores_ = static_cast<uint32_t>(sysconf(_SC_NPROCESSORS_ONLN));
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
                  "Available number of cores:%d", number_of_cores_);
 
-#elif defined(WEBRTC_MAC)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD)
+#if defined(WEBRTC_BSD)
+    int name[] = {CTL_HW, HW_NCPU};
+#else
     int name[] = {CTL_HW, HW_AVAILCPU};
+#endif
     int ncpu;
     size_t size = sizeof(ncpu);
     if (0 == sysctl(name, 2, &ncpu, &size, NULL, 0)) {
