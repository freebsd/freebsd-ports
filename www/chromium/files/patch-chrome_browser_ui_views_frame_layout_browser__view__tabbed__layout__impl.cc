--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -323,7 +323,7 @@ int BrowserViewTabbedLayoutImpl::GetHorizontalTabStrip
 }
 
 int BrowserViewTabbedLayoutImpl::GetVerticalTabStripContentOverlap() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On fractional display scaling (e.g. 1.25x, 1.5x), overlap the content area
   // by 1 DIP over the vertical tab strip border to prevent subpixel seams.
   if (auto* const widget = views().browser_view->GetWidget()) {
