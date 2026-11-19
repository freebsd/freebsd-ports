--- chrome/browser/ui/views/frame/contents_web_view.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/frame/contents_web_view.cc
@@ -29,7 +29,7 @@
 #include "ui/wm/core/window_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/actor/actor_util.h"  // nogncheck
 #endif
 
@@ -181,7 +181,7 @@ void ContentsWebView::SetWebContents(content::WebConte
       .Then(&web_modal::WebContentsModalDialogManager::UpdateDialogHost);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ContentsWebView::DidGetUserInteraction(const blink::WebInputEvent& event) {
   // If the user interacts with the web contents, ensure it is activated.
   // This handles cases where the native window does not receive a focus
