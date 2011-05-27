--- chrome/browser/browser_main_posix.cc.orig	2011-05-27 22:17:55.589297382 +0300
+++ chrome/browser/browser_main_posix.cc	2011-05-27 22:19:02.906188216 +0300
@@ -20,7 +20,7 @@
 #include "chrome/common/chrome_switches.h"
 #include "content/browser/browser_thread.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/printing/print_dialog_gtk.h"
 #endif
 
@@ -236,9 +236,9 @@
     }
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   printing::PrintingContextCairo::SetPrintingFunctions(
       &PrintDialogGtk::CreatePrintDialog,
       &PrintDialogGtk::PrintDocument);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 }
