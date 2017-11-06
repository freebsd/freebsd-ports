--- remoting/base/chromoting_event.cc.orig	2017-08-10 16:16:33.217694000 +0200
+++ remoting/base/chromoting_event.cc	2017-08-10 16:16:51.082041000 +0200
@@ -103,7 +103,7 @@
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif defined(OS_CHROMEOS)
   Os os = Os::CHROMOTING_CHROMEOS;
