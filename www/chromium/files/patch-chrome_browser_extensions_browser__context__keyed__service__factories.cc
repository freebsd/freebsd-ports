--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -52,7 +52,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -88,7 +88,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   extensions::IdentityAPI::GetFactoryInstance();
   extensions::InstallTrackerFactory::GetInstance();
   extensions::InstallVerifierFactory::GetInstance();
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
