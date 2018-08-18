--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2017-12-15 02:04:11.000000000 +0100
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc	2017-12-24 02:45:43.317955000 +0100
@@ -261,7 +261,7 @@
   //     synchronous on desktop Linux, so use that.
   // - Chrome OS
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_tab_offset, mouse_offset.y());
@@ -599,7 +599,7 @@
     else
       target_tabstrip->GetWidget()->SetCapture(attached_tabstrip_);
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) || defined(OS_BSD)
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -1792,7 +1792,7 @@
     if (dragged_window)
       exclude.insert(dragged_window);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
