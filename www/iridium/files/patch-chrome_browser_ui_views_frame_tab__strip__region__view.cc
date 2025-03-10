--- chrome/browser/ui/views/frame/tab_strip_region_view.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/views/frame/tab_strip_region_view.cc
@@ -231,7 +231,7 @@ TabStripRegionView::TabStripRegionView(std::unique_ptr
       new_tab_button_->GetViewAccessibility().SetName(
           l10n_util::GetStringUTF16(IDS_ACCNAME_NEWTAB));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // The New Tab Button can be middle-clicked on Linux.
       new_tab_button_->SetTriggerableEventFlags(
           new_tab_button_->GetTriggerableEventFlags() |
