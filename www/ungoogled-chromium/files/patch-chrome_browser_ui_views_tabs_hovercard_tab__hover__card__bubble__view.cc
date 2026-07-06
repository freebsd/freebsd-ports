--- chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc
@@ -674,7 +674,7 @@ TabHoverCardBubbleView::TabHoverCardBubbleView(
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
