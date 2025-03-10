--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2368,7 +2368,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   contents_web_view_->SetFastResize(is_dragging);
   if (!is_dragging) {
     // When tab dragging is ended, we need to make sure the web contents get
