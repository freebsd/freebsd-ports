--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2017-09-05 21:05:12.000000000 +0200
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc	2017-09-06 18:14:17.437338000 +0200
@@ -61,7 +61,7 @@
 #include "chrome/browser/chromeos/extensions/input_method_api.h"
 #include "chrome/browser/chromeos/extensions/media_player_api.h"
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -105,7 +105,7 @@
 #if defined(OS_CHROMEOS)
   extensions::InputImeAPI::GetFactoryInstance();
   extensions::InputMethodAPI::GetFactoryInstance();
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
