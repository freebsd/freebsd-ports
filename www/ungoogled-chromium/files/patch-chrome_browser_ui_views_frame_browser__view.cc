--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2475,7 +2475,7 @@ void BrowserView::ToolbarSizeChanged(bool is_animating
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
