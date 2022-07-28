--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -53,7 +53,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -132,7 +132,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #endif
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
