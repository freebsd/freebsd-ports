--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -11,7 +11,7 @@
 #include "content/browser/webui/web_ui_impl.h"
 #include "content/public/browser/navigation_handle.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/callback_helpers.h"
 #include "base/feature_list.h"
 #include "base/logging.h"
@@ -30,7 +30,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Remove the pieces of the URL we don't want to send back with the error
 // reports. In particular, do not send query or fragments as those can have
 // privacy-sensitive information in them.
@@ -66,7 +66,7 @@ void WebUIMainFrameObserver::DidFinishNavigation(
   web_ui_->DisallowJavascriptOnAllHandlers();
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebUIMainFrameObserver::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
@@ -183,7 +183,7 @@ void WebUIMainFrameObserver::ReadyToCommitNavigation(
 
 // TODO(crbug.com/1129544) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   MaybeEnableWebUIJavaScriptErrorReporting(navigation_handle);
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 }
