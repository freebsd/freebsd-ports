--- chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc
@@ -16,7 +16,7 @@
 #include "components/send_tab_to_self/features.h"
 #include "components/send_tab_to_self/send_tab_to_self_model.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "chrome/browser/ui/send_tab_to_self/send_tab_to_self_toolbar_icon_controller.h"
 #endif
@@ -50,7 +50,7 @@ void SendTabToSelfClientService::SendTabToSelfModelLoa
 void SendTabToSelfClientService::EntriesAddedRemotely(
     const std::vector<const SendTabToSelfEntry*>& new_entries) {
   for (const std::unique_ptr<ReceivingUiHandler>& handler : GetHandlers()) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     // Only respond to notifications corresponding to this service's profile
     // for these OSes; mobile does not have a Profile.
