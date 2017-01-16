--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2016-12-01 23:02:07.000000000 +0000
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc	2016-12-16 19:35:19.489404000 +0000
@@ -62,7 +62,7 @@
 #include "chrome/browser/chromeos/extensions/media_player_api.h"
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #include "chrome/browser/extensions/api/log_private/log_private_api.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -103,7 +103,7 @@
 #if defined(OS_CHROMEOS)
   extensions::InputImeAPI::GetFactoryInstance();
   extensions::InputMethodAPI::GetFactoryInstance();
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) && !defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
