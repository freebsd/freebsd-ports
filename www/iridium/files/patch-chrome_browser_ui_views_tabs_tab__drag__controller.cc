--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc
@@ -251,7 +251,7 @@ void TabDragController::Init(
   //     synchronous on desktop Linux, so use that.
   // - Ash
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if defined(OS_LINUX) || defined(USE_ASH)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_ASH)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_tab_offset, mouse_offset.y());
@@ -597,7 +597,7 @@ TabDragController::DragBrowserToNewTabSt
     else
       target_tabstrip->GetWidget()->SetCapture(attached_tabstrip_);
 
-#if !defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -1787,7 +1787,7 @@ TabDragController::Liveness TabDragContr
     if (dragged_window)
       exclude.insert(dragged_window);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
