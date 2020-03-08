--- chrome/browser/ui/views/tabs/tab.cc.orig	2019-12-16 21:51:24 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -582,7 +582,7 @@ void Tab::OnMouseEntered(const ui::MouseEvent& event) 
   if (mouse_hovered_ || !GetWidget()->IsMouseEventsEnabled())
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug/978134): Once Linux/CrOS widget transparency is solved, remove
