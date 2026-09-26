--- chrome/browser/ui/views/tabs/dragging/tab_drag_controller.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/tabs/dragging/tab_drag_controller.cc
@@ -103,7 +103,7 @@
 #include "ui/wm/core/window_modality_controller.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h"
 #endif
 
@@ -223,7 +223,7 @@ BrowserView* GetBrowserViewForContext(const TabDragCon
 
 void UpdateSystemDnDDragImage(TabDragContext* attached_context,
                               const gfx::ImageSkia& image) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   VLOG(1) << __func__ << " image size=" << image.size().ToString();
   aura::Window* root_window =
       attached_context->GetWidget()->GetNativeWindow()->GetRootWindow();
@@ -432,7 +432,7 @@ TabDragController::Liveness TabDragController::Init(
   //     synchronous on desktop Linux, so use that.
   // - ChromeOS Ash
   //     Releasing capture on Ash cancels gestures so avoid it.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ref->can_release_capture_ = false;
 #endif
   ref->start_point_in_screen_ =
@@ -1103,7 +1103,7 @@ TabDragController::Liveness TabDragController::DragBro
       CHECK_EQ(SetCapture(target_context), Liveness::kAlive);
     }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const bool is_dragging_all_tabs =
         source_context_ && drag_data_.num_dragging_tabs() ==
                                source_context_->GetTabStripModel()->count();
@@ -1796,7 +1796,7 @@ TabDragController::DetachIntoNewBrowserAndRunMoveLoop(
       current_state_ = DragState::kWaitingForWindowToShow;
       VisibilityWaiter waiter(dragged_widget);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // VisibilityWaiter runs a kNestableTasksAllowed loop while the user holds
       // the pointer button, before the move loop's own suppression scope is
       // established; suppress data drags for its duration as well.
@@ -2426,7 +2426,7 @@ void TabDragController::CompleteDrag() {
     }
 
     // If source window was maximized - maximize the new window as well.
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
     // Keeping maximized state breaks snap to Grid on Windows when dragging
     // tabs from maximized windows. TODO:(crbug.com/41321838) Explore doing this
     // for other desktop OS's. kMaximizedStateRetainedOnTabDrag in
@@ -2854,7 +2854,7 @@ TabDragController::Liveness TabDragController::GetLoca
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Exclude windows which are pending deletion via Browser::TabStripEmpty().
   // These windows can be returned in the Linux Aura port because the browser
   // window which was used for dragging is not hidden once all of its tabs are
