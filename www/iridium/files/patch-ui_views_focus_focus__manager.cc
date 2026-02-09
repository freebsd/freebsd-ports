--- ui/views/focus/focus_manager.cc.orig	2026-02-16 10:45:29 UTC
+++ ui/views/focus/focus_manager.cc
@@ -609,7 +609,7 @@ bool FocusManager::RedirectAcceleratorToParentWidget(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Processing an accelerator can delete things. Because we
   // need these objects afterwards on Linux, save widget_ as weak pointer and
   // save the close_on_deactivate property value of widget_delegate in a
@@ -627,7 +627,7 @@ bool FocusManager::RedirectAcceleratorToParentWidget(
   const bool accelerator_processed =
       focus_manager->ProcessAccelerator(accelerator);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Need to manually close the bubble widget on Linux. On Linux when the
   // bubble is shown, the main widget remains active. Because of that when
   // focus is set to the main widget to process accelerator, the main widget
