--- src/3rdparty/chromium/extensions/browser/api/messaging/message_service.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/extensions/browser/api/messaging/message_service.cc
@@ -71,7 +71,7 @@ const char kReceivingEndDoesntExistError[] =
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -490,7 +490,7 @@ void MessageService::OpenChannelToNativeApp(
     return;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       mojom::APIPermissionID::kNativeMessaging);
   if (!has_permission) {
