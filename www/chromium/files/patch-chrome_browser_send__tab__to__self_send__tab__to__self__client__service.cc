--- chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/send_tab_to_self/send_tab_to_self_client_service.cc
@@ -40,7 +40,7 @@ void SendTabToSelfClientService::SendTabToSelfModelLoa
 void SendTabToSelfClientService::EntriesAddedRemotely(
     const std::vector<const SendTabToSelfEntry*>& new_entries) {
   for (const std::unique_ptr<ReceivingUiHandler>& handler : GetHandlers()) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     // Only respond to notifications corresponding to this service's profile
     // for these OSes; mobile does not have a Profile.
