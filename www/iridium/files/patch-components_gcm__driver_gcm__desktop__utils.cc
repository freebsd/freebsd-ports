--- components/gcm_driver/gcm_desktop_utils.cc.orig	2025-12-10 15:04:57 UTC
+++ components/gcm_driver/gcm_desktop_utils.cc
@@ -32,7 +32,7 @@ GCMClient::ChromePlatform GetPlatform() {
   return GCMClient::PLATFORM_ANDROID;
 #elif BUILDFLAG(IS_CHROMEOS)
   return GCMClient::PLATFORM_CROS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GCMClient::PLATFORM_LINUX;
 #else
   // For all other platforms, return as LINUX.
