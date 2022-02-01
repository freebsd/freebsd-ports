--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc
@@ -440,7 +440,7 @@ void TabDragController::Init(TabDragContext* source_co
   //     synchronous on desktop Linux, so use that.
   // - Chrome OS
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_view_offset, mouse_offset.y());
@@ -888,7 +888,7 @@ TabDragController::DragBrowserToNewTabStrip(TabDragCon
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -2097,7 +2097,7 @@ TabDragController::Liveness TabDragController::GetLoca
   }
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
