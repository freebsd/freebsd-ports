--- ui/views/selection_controller.cc.orig	2017-04-19 19:06:55 UTC
+++ ui/views/selection_controller.cc
@@ -20,7 +20,7 @@ SelectionController::SelectionController
       delegate_(delegate),
       handles_selection_clipboard_(false) {
 // On Linux, update the selection clipboard on a text selection.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_handles_selection_clipboard(true);
 #endif
 
