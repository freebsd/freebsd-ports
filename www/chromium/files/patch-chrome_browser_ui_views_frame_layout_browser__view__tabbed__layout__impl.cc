--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -250,7 +250,7 @@ int BrowserViewTabbedLayoutImpl::GetHorizontalTabStrip
 }
 
 bool BrowserViewTabbedLayoutImpl::AvoidCrackingForFractionalDisplay() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // This is primarily an issue on Linux and Windows; add other platforms here
   // as needed.
   if (auto* const widget = views().browser_view->GetWidget()) {
