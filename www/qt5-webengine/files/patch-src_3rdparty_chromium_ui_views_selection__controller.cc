--- src/3rdparty/chromium/ui/views/selection_controller.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/selection_controller.cc
@@ -23,7 +23,7 @@ SelectionController::SelectionController(SelectionCont
       delegate_(delegate),
       handles_selection_clipboard_(false) {
 // On Linux, update the selection clipboard on a text selection.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_handles_selection_clipboard(true);
 #endif
 
