--- chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc
@@ -244,7 +244,7 @@ HorizontalTabStripRegionViewOld::HorizontalTabStripReg
     new_tab_button_->GetViewAccessibility().SetName(
         l10n_util::GetStringUTF16(IDS_ACCNAME_NEWTAB));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, middle-clicking the New Tab Button triggers
     // paste and navigate, either to URLs or to search queries.
     new_tab_button_->SetTriggerableEventFlags(
