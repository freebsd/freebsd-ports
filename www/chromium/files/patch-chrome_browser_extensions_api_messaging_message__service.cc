--- chrome/browser/extensions/api/messaging/message_service.cc.orig	2016-05-21 16:16:28 UTC
+++ chrome/browser/extensions/api/messaging/message_service.cc
@@ -118,7 +118,7 @@ MessageService::PolicyPermission Message
 
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -415,7 +415,7 @@ void MessageService::OpenChannelToNative
   if (!source)
     return;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   Profile* profile =
       Profile::FromBrowserContext(source->GetProcess()->GetBrowserContext());
   ExtensionService* extension_service =
