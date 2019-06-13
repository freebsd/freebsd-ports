--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc
@@ -436,7 +436,7 @@ void TabDragController::Init(TabStrip* source_tabstrip
   //     synchronous on desktop Linux, so use that.
   // - Chrome OS
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_tab_offset, mouse_offset.y());
@@ -868,7 +868,7 @@ TabDragController::DragBrowserToNewTabStrip(TabStrip* 
     else
       target_tabstrip->GetWidget()->SetCapture(attached_tabstrip_);
 
-#if !defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (!defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_BSD)
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -2044,7 +2044,7 @@ TabDragController::Liveness TabDragController::GetLoca
       exclude.insert(dragged_window);
     }
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
