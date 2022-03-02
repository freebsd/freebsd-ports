--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -52,7 +52,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -124,7 +124,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
   extensions::SignedInDevicesManager::GetFactoryInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
