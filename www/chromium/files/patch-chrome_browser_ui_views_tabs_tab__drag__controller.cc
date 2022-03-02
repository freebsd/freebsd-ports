--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc
@@ -468,7 +468,7 @@ void TabDragController::Init(TabDragContext* source_co
   //     synchronous on desktop Linux, so use that.
   // - Chrome OS
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_view_offset, mouse_offset.y());
@@ -916,7 +916,7 @@ TabDragController::DragBrowserToNewTabStrip(TabDragCon
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -2128,7 +2128,7 @@ TabDragController::Liveness TabDragController::GetLoca
   }
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
