--- chrome/browser/browser_main_posix.cc.orig	2011-05-06 12:03:38.000000000 +0300
+++ chrome/browser/browser_main_posix.cc	2011-06-03 23:58:29.518404852 +0300
@@ -20,7 +20,7 @@
 #include "chrome/common/chrome_switches.h"
 #include "content/browser/browser_thread.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/printing/print_dialog_gtk.h"
 #endif
 
@@ -230,8 +230,8 @@
     }
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   printing::PrintingContextCairo::SetCreatePrintDialogFunction(
       &PrintDialogGtk::CreatePrintDialog);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 }
