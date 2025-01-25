--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2360,7 +2360,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   contents_web_view_->SetFastResize(is_dragging);
   if (!is_dragging) {
     // When tab dragging is ended, we need to make sure the web contents get
