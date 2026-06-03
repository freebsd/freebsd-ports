--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -27,7 +27,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> CreatePlatform
 #if BUILDFLAG(IS_CHROMEOS)
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state,
                                                          os_crypt_async);
 #else
