--- components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2025-12-10 15:04:57 UTC
+++ components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -119,7 +119,7 @@ std::ostream& operator<<(std::ostream& os, const ListI
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
