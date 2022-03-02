--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -12,7 +12,7 @@
 #include "content/browser/webui/web_ui_impl.h"
 #include "content/public/browser/navigation_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/callback_helpers.h"
 #include "base/feature_list.h"
 #include "base/logging.h"
@@ -31,7 +31,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Remove the pieces of the URL we don't want to send back with the error
 // reports. In particular, do not send query or fragments as those can have
 // privacy-sensitive information in them.
@@ -67,7 +67,7 @@ void WebUIMainFrameObserver::DidFinishNavigation(
   web_ui_->DisallowJavascriptOnAllHandlers();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void WebUIMainFrameObserver::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
@@ -175,7 +175,7 @@ void WebUIMainFrameObserver::ReadyToCommitNavigation(
 
 // TODO(crbug.com/1129544) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   MaybeEnableWebUIJavaScriptErrorReporting(navigation_handle);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
