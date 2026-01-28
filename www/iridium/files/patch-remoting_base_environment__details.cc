--- remoting/base/environment_details.cc.orig	2026-01-16 14:21:21 UTC
+++ remoting/base/environment_details.cc
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "remoting/base/version.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #endif
 
@@ -28,7 +28,7 @@ std::string GetOperatingSystemName() {
   return "Mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ChromeOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Linux";
 #elif BUILDFLAG(IS_ANDROID)
   return "Android";
@@ -40,7 +40,7 @@ std::string GetOperatingSystemName() {
 // Get the Operating System Version, removing the need to check for OS
 // definitions and keeps the format used consistent.
 std::string GetOperatingSystemVersion() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::GetLinuxDistro();
 #else
   return base::SysInfo::OperatingSystemVersion();
