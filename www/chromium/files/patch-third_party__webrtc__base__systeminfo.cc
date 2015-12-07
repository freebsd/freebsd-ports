--- third_party/webrtc/base/systeminfo.cc.orig	2015-10-13 15:04:44.000000000 -0400
+++ third_party/webrtc/base/systeminfo.cc	2015-10-14 12:09:17.133190000 -0400
@@ -20,8 +20,12 @@
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
@@ -68,8 +72,12 @@
   number_of_cores = static_cast<int>(si.dwNumberOfProcessors);
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
   number_of_cores = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
-#elif defined(WEBRTC_MAC)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD)
+#if defined(WEBRTC_BSD)
+  int name[] = {CTL_HW, HW_NCPU};
+#else
   int name[] = {CTL_HW, HW_AVAILCPU};
+#endif
   size_t size = sizeof(number_of_cores);
   if (0 != sysctl(name, 2, &number_of_cores, &size, NULL, 0)) {
     LOG(LS_ERROR) << "Failed to get number of cores";
