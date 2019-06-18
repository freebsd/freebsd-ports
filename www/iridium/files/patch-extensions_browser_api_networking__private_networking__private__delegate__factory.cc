--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2019-03-11 22:00:58 UTC
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -11,7 +11,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif defined(OS_WIN) || defined(OS_MACOSX)
 #include "components/wifi/wifi_service.h"
@@ -61,7 +61,7 @@ KeyedService* NetworkingPrivateDelegateFactory::BuildS
   NetworkingPrivateDelegate* delegate;
 #if defined(OS_CHROMEOS)
   delegate = new NetworkingPrivateChromeOS(browser_context);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   delegate = new NetworkingPrivateLinux();
 #elif defined(OS_WIN) || defined(OS_MACOSX)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
