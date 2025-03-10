--- src/3rdparty/chromium/chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc.orig	2024-01-30 07:53:34 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc
@@ -44,7 +44,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "printing/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -127,7 +127,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
   extensions::SidePanelService::GetFactoryInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
