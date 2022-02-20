--- chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc
@@ -17,7 +17,7 @@
 #include "components/send_tab_to_self/send_tab_to_self_model.h"
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/ui/send_tab_to_self/send_tab_to_self_toolbar_icon_controller.h"
 #endif
 
@@ -51,7 +51,7 @@ void SendTabToSelfClientService::EntriesAddedRemotely(
     const std::vector<const SendTabToSelfEntry*>& new_entries) {
   for (const std::unique_ptr<ReceivingUiHandler>& handler : GetHandlers()) {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
     // Only respond to notifications corresponding to this service's profile
     // for these OSes; mobile does not have a Profile.
     // Cast note: on desktop, handlers are guaranteed to be the derived class
