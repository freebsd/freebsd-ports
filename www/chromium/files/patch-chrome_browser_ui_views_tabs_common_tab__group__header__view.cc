--- chrome/browser/ui/views/tabs/common/tab_group_header_view.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/tabs/common/tab_group_header_view.cc
@@ -392,7 +392,7 @@ void TabGroupHeaderView::OnMouseEntered(const ui::Mous
 }
 
 void TabGroupHeaderView::OnMouseExited(const ui::MouseEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Bypasses the synchronous IsMouseHovered() check which can be stale on Linux
   // Wayland/X11 due to asynchronous cursor updates during mouse exit events.
   SetEditorBubbleButtonVisibilityOnHover(/*is_hovered=*/false);
