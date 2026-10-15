--- chrome/browser/ui/views/frame/contents_web_view.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/frame/contents_web_view.cc
@@ -169,7 +169,7 @@ void ContentsWebView::SetWebContents(content::WebConte
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ContentsWebView::DidGetUserInteraction(const blink::WebInputEvent& event) {
   // If the user interacts with the web contents, ensure it is activated.
   // This handles cases where the native window does not receive a focus
