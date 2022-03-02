--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -12,7 +12,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -62,7 +62,7 @@ KeyedService* NetworkingPrivateDelegateFactory::BuildS
   NetworkingPrivateDelegate* delegate;
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   delegate = new NetworkingPrivateChromeOS(browser_context);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   delegate = new NetworkingPrivateLinux();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
