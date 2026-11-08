--- chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.cc
@@ -25,7 +25,7 @@ VerticalTabStripFocusSwipeController::~VerticalTabStri
   region_view_->RemovePreTargetHandler(this);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void VerticalTabStripFocusSwipeController::OnMouseEvent(ui::MouseEvent* event) {
   if (!base::FeatureList::IsEnabled(features::kTabGroupsFocusing) ||
       !region_view_ || region_view_->IsDragging() ||
