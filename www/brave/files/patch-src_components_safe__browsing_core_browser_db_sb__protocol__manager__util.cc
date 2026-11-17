--- src/components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc
@@ -219,7 +219,7 @@ std::ostream& operator<<(std::ostream& o
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
