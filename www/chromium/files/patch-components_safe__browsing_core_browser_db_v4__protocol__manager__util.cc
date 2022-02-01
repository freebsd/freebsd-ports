--- components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2022-01-21 13:23:10 UTC
+++ components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -115,7 +115,7 @@ std::ostream& operator<<(std::ostream& os, const ListI
 PlatformType GetCurrentPlatformType() {
 #if defined(OS_WIN)
   return WINDOWS_PLATFORM;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return LINUX_PLATFORM;
 #elif defined(OS_IOS)
   return IOS_PLATFORM;
