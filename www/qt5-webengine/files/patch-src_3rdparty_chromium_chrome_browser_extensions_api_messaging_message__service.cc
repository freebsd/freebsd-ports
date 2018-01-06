--- src/3rdparty/chromium/chrome/browser/extensions/api/messaging/message_service.cc.orig	2017-01-26 00:49:08 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/messaging/message_service.cc
@@ -119,7 +119,7 @@ MessageService::PolicyPermission Message
 
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -414,7 +414,7 @@ void MessageService::OpenChannelToNative
   if (!source)
     return;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   content::WebContents* web_contents =
       content::WebContents::FromRenderFrameHost(source);
   ExtensionWebContentsObserver* extension_web_contents_observer =
@@ -477,12 +477,12 @@ void MessageService::OpenChannelToNative
   channel->opener->IncrementLazyKeepaliveCount();
 
   AddChannel(std::move(channel), receiver_port_id);
-#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD))
   const char kNativeMessagingNotSupportedError[] =
       "Native Messaging is not supported on this platform.";
   DispatchOnDisconnect(
       source, receiver_port_id, kNativeMessagingNotSupportedError);
-#endif  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#endif  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD))
 }
 
 void MessageService::OpenChannelToTab(int source_process_id,
