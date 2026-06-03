--- components/wallet/core/browser/network/wallet_request.cc.orig	2026-05-09 18:09:27 UTC
+++ components/wallet/core/browser/network/wallet_request.cc
@@ -19,7 +19,7 @@ ClientInfo::ChromeClientInfo::Platform GetPlatform() {
   return ClientInfo::ChromeClientInfo::PLATFORM_MACOS;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ClientInfo::ChromeClientInfo::PLATFORM_CHROMEOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ClientInfo::ChromeClientInfo::PLATFORM_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   return ClientInfo::ChromeClientInfo::PLATFORM_ANDROID;
