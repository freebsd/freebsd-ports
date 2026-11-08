--- chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.h
@@ -31,7 +31,7 @@ class VerticalTabStripFocusSwipeController : public ui
   ~VerticalTabStripFocusSwipeController() override;
 
   // ui::EventHandler:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnMouseEvent(ui::MouseEvent* event) override;
 #elif BUILDFLAG(IS_MAC)
   void OnScrollEvent(ui::ScrollEvent* event) override;
