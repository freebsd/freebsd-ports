--- extensions/browser/api/messaging/message_service.cc.orig	2019-04-30 22:22:49 UTC
+++ extensions/browser/api/messaging/message_service.cc
@@ -60,7 +60,7 @@ namespace {
 
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -374,7 +374,7 @@ void MessageService::OpenChannelToNativeApp(
   if (!opener_port->IsValidPort())
     return;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       APIPermission::kNativeMessaging);
   if (!has_permission) {
@@ -420,11 +420,11 @@ void MessageService::OpenChannelToNativeApp(
   channel->opener->IncrementLazyKeepaliveCount();
 
   AddChannel(std::move(channel), receiver_port_id);
-#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD))
   const char kNativeMessagingNotSupportedError[] =
       "Native Messaging is not supported on this platform.";
   opener_port->DispatchOnDisconnect(kNativeMessagingNotSupportedError);
-#endif  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#endif  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD))
 }
 
 void MessageService::OpenChannelToTab(int source_process_id,
