--- remoting/host/host_details.cc.orig	2017-05-09 19:02:49 UTC
+++ remoting/host/host_details.cc
@@ -26,6 +26,8 @@ std::string GetHostOperatingSystemName()
   return "Linux";
 #elif defined(OS_ANDROID)
   return "Android";
+#elif defined(OS_BSD)
+  return "BSD";
 #else
 #error "Unsupported host OS"
 #endif
