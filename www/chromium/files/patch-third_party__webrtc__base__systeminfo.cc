--- third_party/webrtc/base/systeminfo.cc.orig	2015-10-14 18:48:28.088649000 +0200
+++ third_party/webrtc/base/systeminfo.cc	2015-10-14 18:57:35.819790000 +0200
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
@@ -66,7 +70,7 @@
   SYSTEM_INFO si;
   GetSystemInfo(&si);
   number_of_cores = static_cast<int>(si.dwNumberOfProcessors);
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
   number_of_cores = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
 #elif defined(WEBRTC_MAC)
   int name[] = {CTL_HW, HW_AVAILCPU};
@@ -174,9 +178,13 @@
     LOG_GLE(LS_WARNING) << "GlobalMemoryStatusEx failed.";
   }
 
-#elif defined(WEBRTC_MAC)
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_BSD)
   size_t len = sizeof(memory);
+  #if defined(WEBRTC_MAC) 
   int error = sysctlbyname("hw.memsize", &memory, &len, NULL, 0);
+  #else
+  int error = sysctlbyname("hw.physmem", &memory, &len, NULL, 0);
+  #endif
   if (error || memory == 0)
     memory = -1;
 #else  // WEBRTC_LINUX
