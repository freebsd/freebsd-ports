--- chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc
@@ -43,7 +43,7 @@
 #include "extensions/browser/api/bluetooth_low_energy/bluetooth_low_energy_api.h"
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -115,7 +115,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
   extensions::SidePanelService::GetFactoryInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
