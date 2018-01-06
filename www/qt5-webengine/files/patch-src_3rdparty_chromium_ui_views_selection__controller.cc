--- src/3rdparty/chromium/ui/views/selection_controller.cc.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/views/selection_controller.cc
@@ -20,7 +20,7 @@ SelectionController::SelectionController
       delegate_(delegate),
       handles_selection_clipboard_(false) {
 // On Linux, update the selection clipboard on a text selection.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_handles_selection_clipboard(true);
 #endif
 
