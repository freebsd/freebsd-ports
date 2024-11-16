--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2024-11-14 07:57:23 UTC
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -12,7 +12,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -63,7 +63,7 @@ NetworkingPrivateDelegateFactory::BuildServiceInstance
   std::unique_ptr<NetworkingPrivateDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS)
   delegate = std::make_unique<NetworkingPrivateChromeOS>(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = std::make_unique<NetworkingPrivateLinux>();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
