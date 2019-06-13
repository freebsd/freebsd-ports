--- chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc.orig	2019-06-07 20:47:39 UTC
+++ chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/browser/send_tab_to_self/receiving_ui_handler.h"
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #endif
 
@@ -32,7 +32,7 @@ ReceivingUiHandlerRegistry* ReceivingUiHandlerRegistry
 // Instantiates all the handlers relevant to this platform.
 void ReceivingUiHandlerRegistry::InstantiatePlatformSpecificHandlers(
     Profile* profile) {
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   applicable_handlers_.push_back(
       std::make_unique<send_tab_to_self::DesktopNotificationHandler>(profile));
 #elif defined(OS_ANDROID)
