--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2021-01-18 21:28:57 UTC
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -10,7 +10,7 @@
 #include "content/browser/webui/web_ui_impl.h"
 #include "content/public/browser/navigation_handle.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/callback_helpers.h"
 #include "base/feature_list.h"
 #include "base/logging.h"
@@ -41,7 +41,7 @@ void WebUIMainFrameObserver::DidFinishNavigation(
   web_ui_->DisallowJavascriptOnAllHandlers();
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebUIMainFrameObserver::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
@@ -101,6 +101,6 @@ void WebUIMainFrameObserver::OnDidAddMessageToConsole(
   processor->SendErrorReport(std::move(report), base::DoNothing(),
                              web_contents()->GetBrowserContext());
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace content
