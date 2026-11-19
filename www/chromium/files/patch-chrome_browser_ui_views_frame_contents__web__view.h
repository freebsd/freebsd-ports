--- chrome/browser/ui/views/frame/contents_web_view.h.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/frame/contents_web_view.h
@@ -63,7 +63,7 @@ class ContentsWebView : public views::WebView,
   // This allows the browser to force focus synchronization in split view even
   // when native OS focus gets stuck on a different window (like a permission
   // prompt).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void DidGetUserInteraction(const blink::WebInputEvent& event) override;
 #endif
 
