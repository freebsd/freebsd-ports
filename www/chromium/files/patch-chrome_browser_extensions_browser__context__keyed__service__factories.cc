--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -53,7 +53,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/system_indicator/system_indicator_manager_factory.h"
 #endif
 
@@ -126,7 +126,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   extensions::SettingsPrivateEventRouterFactory::GetInstance();
   extensions::SettingsOverridesAPI::GetFactoryInstance();
   extensions::SignedInDevicesManager::GetFactoryInstance();
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
   extensions::SystemIndicatorManagerFactory::GetInstance();
 #endif
   extensions::TabGroupsEventRouterFactory::GetInstance();
