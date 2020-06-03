--- chrome/browser/ui/views/tabs/tab.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -596,7 +596,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
   if (mouse_hovered_ || !GetWidget()->IsMouseEventsEnabled())
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug/978134): Once Linux/CrOS widget transparency is solved, remove
