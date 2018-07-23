--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2018-06-13 00:10:06.000000000 +0200
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc	2018-07-15 13:15:07.666902000 +0200
@@ -57,7 +57,7 @@
 #include "chrome/browser/chromeos/extensions/media_player_api.h"
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #include "chrome/browser/extensions/api/screenlock_private/screenlock_private_api.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -99,7 +99,7 @@
 #if defined(OS_CHROMEOS)
   extensions::InputImeAPI::GetFactoryInstance();
   extensions::InputMethodAPI::GetFactoryInstance();
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
