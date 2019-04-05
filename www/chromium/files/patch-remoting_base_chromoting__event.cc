--- remoting/base/chromoting_event.cc.orig	2019-03-11 22:01:01 UTC
+++ remoting/base/chromoting_event.cc
@@ -189,7 +189,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, GetOperatingSystemVersionString());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif defined(OS_CHROMEOS)
   Os os = Os::CHROMOTING_CHROMEOS;
