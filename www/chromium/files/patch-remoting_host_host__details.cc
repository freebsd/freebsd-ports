--- remoting/host/host_details.cc.orig	2021-03-12 23:57:28 UTC
+++ remoting/host/host_details.cc
@@ -25,6 +25,8 @@ std::string GetHostOperatingSystemName() {
   return "ChromeOS";
 #elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
   return "Linux";
+#elif defined(OS_FREEBSD)
+  return "FreeBSD";
 #elif defined(OS_ANDROID)
   return "Android";
 #else
