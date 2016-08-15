--- chrome/browser/extensions/api/messaging/message_service.cc.orig	2016-07-22 00:06:51.000000000 -0400
+++ chrome/browser/extensions/api/messaging/message_service.cc	2016-08-03 11:20:56.579570000 -0400
@@ -119,7 +119,7 @@
 
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -415,7 +415,7 @@
   if (!source)
     return;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   content::WebContents* web_contents =
       content::WebContents::FromRenderFrameHost(source);
   ExtensionWebContentsObserver* extension_web_contents_observer =
