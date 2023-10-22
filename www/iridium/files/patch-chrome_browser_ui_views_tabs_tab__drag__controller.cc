--- chrome/browser/ui/views/tabs/tab_drag_controller.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/ui/views/tabs/tab_drag_controller.cc
@@ -91,7 +91,7 @@
 #include "components/remote_cocoa/browser/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/aura/client/drag_drop_client.h"
 #endif
 
@@ -208,7 +208,7 @@ bool IsWindowDragUsingSystemDragDropAllowed() {
 
 void UpdateSystemDnDDragImage(TabDragContext* attached_context,
                               const gfx::ImageSkia& image) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   aura::Window* root_window =
       attached_context->GetWidget()->GetNativeWindow()->GetRootWindow();
   if (aura::client::GetDragDropClient(root_window)) {
@@ -388,7 +388,7 @@ void TabDragController::Init(TabDragContext* source_co
   //     synchronous on desktop Linux, so use that.
   // - ChromeOS Ash
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   can_release_capture_ = false;
 #endif
   start_point_in_screen_ = gfx::Point(source_view_offset, mouse_offset.y());
@@ -1013,7 +1013,7 @@ TabDragController::DragBrowserToNewTabStrip(TabDragCon
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
     // EndMoveLoop is going to snap the window back to its original location.
     // Hide it so users don't see this. Hiding a window in Linux aura causes
     // it to lose capture so skip it.
@@ -2053,7 +2053,7 @@ void TabDragController::CompleteDrag() {
       }
 
       // If source window was maximized - maximize the new window as well.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
       // Keeping maximized state breaks snap to Grid on Windows when dragging
       // tabs from maximized windows. TODO:(crbug.com/727051) Explore doing this
       // for other desktop OS's. kMaximizedStateRetainedOnTabDrag in
@@ -2485,7 +2485,7 @@ TabDragController::Liveness TabDragController::GetLoca
   }
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
