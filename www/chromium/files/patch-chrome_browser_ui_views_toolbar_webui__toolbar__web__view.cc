--- chrome/browser/ui/views/toolbar/webui_toolbar_web_view.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/ui/views/toolbar/webui_toolbar_web_view.cc
@@ -553,7 +553,7 @@ void WebUIToolbarWebView::AddedToWidget() {
     if (features::IsWebUIExtensionsContainerEnabled()) {
       extensions_container_.Init(web_contents());
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (features::IsWebUIMediaButtonEnabled()) {
       media_control_.Init();
     }
@@ -945,7 +945,7 @@ WebUIToolbarWebView::GetAvatarToolbarButtonInterface()
 }
 
 MediaToolbarButton* WebUIToolbarWebView::GetMediaToolbarButton() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWebUIMediaButtonEnabled()) {
     return &media_control_;
   }
@@ -1800,7 +1800,7 @@ gfx::Size WebUIToolbarWebView::ComputeLayout(
   button_count += features::IsWebUIAppMenuButtonEnabled();
   button_count +=
       features::IsWebUIGlicButtonEnabled() && glic_control_.IsVisible();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   button_count +=
       features::IsWebUIMediaButtonEnabled() && media_control_.IsButtonShowing();
 #endif
