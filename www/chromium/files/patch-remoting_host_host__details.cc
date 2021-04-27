--- remoting/host/host_details.cc.orig	2021-04-14 18:41:08 UTC
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
