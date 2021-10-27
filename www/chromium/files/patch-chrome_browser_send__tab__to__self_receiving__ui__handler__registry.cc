--- chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc.orig	2021-09-24 04:25:59 UTC
+++ chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/send_tab_to_self/receiving_ui_handler.h"
 #include "components/send_tab_to_self/features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/ui/send_tab_to_self/send_tab_to_self_toolbar_icon_controller.h"
@@ -36,7 +36,7 @@ ReceivingUiHandlerRegistry* ReceivingUiHandlerRegistry
 // Instantiates all the handlers relevant to this platform.
 void ReceivingUiHandlerRegistry::InstantiatePlatformSpecificHandlers(
     Profile* profile) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 
   // If STTS 2.0 is enabled the handler will be created when the toolbar
@@ -55,7 +55,7 @@ void ReceivingUiHandlerRegistry::InstantiatePlatformSp
 SendTabToSelfToolbarIconController*
 ReceivingUiHandlerRegistry::GetToolbarButtonControllerForProfile(
     Profile* profile) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
   for (const std::unique_ptr<ReceivingUiHandler>& handler :
        applicable_handlers_) {
