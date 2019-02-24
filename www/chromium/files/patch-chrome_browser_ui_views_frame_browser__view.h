--- chrome/browser/ui/views/frame/browser_view.h.orig	2019-02-06 22:45:00.117437000 +0100
+++ chrome/browser/ui/views/frame/browser_view.h	2019-02-06 22:46:12.076822000 +0100
@@ -49,7 +49,7 @@
 #include "chrome/browser/ui/views/intent_picker_bubble_view.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/ui/views/quit_instruction_bubble_controller.h"
 #endif
 
@@ -833,7 +833,7 @@
   };
   base::Optional<ResizeSession> interactive_resize_;
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   scoped_refptr<QuitInstructionBubbleController>
       quit_instruction_bubble_controller_;
 #endif
