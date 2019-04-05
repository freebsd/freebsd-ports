--- src/3rdparty/chromium/ui/views/selection_controller.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/views/selection_controller.cc
@@ -20,7 +20,7 @@ SelectionController::SelectionController(SelectionCont
       delegate_(delegate),
       handles_selection_clipboard_(false) {
 // On Linux, update the selection clipboard on a text selection.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_handles_selection_clipboard(true);
 #endif
 
