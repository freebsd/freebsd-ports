--- src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -14,7 +14,7 @@
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "extensions/browser/api/networking_private/networking_private_lacros.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -68,7 +68,7 @@ KeyedService* NetworkingPrivateDelegateFactory::BuildS
   delegate = new NetworkingPrivateChromeOS(browser_context);
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   delegate = new NetworkingPrivateLacros(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = new NetworkingPrivateLinux();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
