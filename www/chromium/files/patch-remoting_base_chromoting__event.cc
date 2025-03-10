--- remoting/base/chromoting_event.cc.orig	2025-03-05 08:14:56 UTC
+++ remoting/base/chromoting_event.cc
@@ -191,7 +191,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif BUILDFLAG(IS_CHROMEOS)
   Os os = Os::CHROMOTING_CHROMEOS;
