--- chrome/browser/ui/views/tabs/tab.cc.orig	2020-03-16 18:40:30 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -584,7 +584,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
   if (mouse_hovered_ || !GetWidget()->IsMouseEventsEnabled())
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug/978134): Once Linux/CrOS widget transparency is solved, remove
