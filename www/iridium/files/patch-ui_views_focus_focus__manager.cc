--- ui/views/focus/focus_manager.cc.orig	2025-02-22 18:06:53 UTC
+++ ui/views/focus/focus_manager.cc
@@ -603,7 +603,7 @@ bool FocusManager::RedirectAcceleratorToBubbleAnchorWi
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Processing an accelerator can delete things. Because we
   // need these objects afterwards on Linux, save widget_ as weak pointer and
   // save the close_on_deactivate property value of widget_delegate in a
@@ -618,7 +618,7 @@ bool FocusManager::RedirectAcceleratorToBubbleAnchorWi
   const bool accelerator_processed =
       focus_manager->ProcessAccelerator(accelerator);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Need to manually close the bubble widget on Linux. On Linux when the
   // bubble is shown, the main widget remains active. Because of that when
   // focus is set to the main widget to process accelerator, the main widget
