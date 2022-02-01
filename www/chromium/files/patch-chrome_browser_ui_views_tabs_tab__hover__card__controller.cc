--- chrome/browser/ui/views/tabs/tab_hover_card_controller.cc.orig	2021-12-14 11:45:00 UTC
+++ chrome/browser/ui/views/tabs/tab_hover_card_controller.cc
@@ -302,7 +302,7 @@ void TabHoverCardController::ShowHoverCard(bool is_ini
   slide_animator_->UpdateTargetBounds();
   MaybeStartThumbnailObservation(target_tab_, is_initial);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Ensure the hover card Widget assumes the highest z-order to avoid occlusion
   // by other secondary UI Widgets (such as the omnibox Widget, see
   // crbug.com/1226536).
