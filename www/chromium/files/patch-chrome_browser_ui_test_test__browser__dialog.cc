--- chrome/browser/ui/test/test_browser_dialog.cc.orig	2021-09-14 01:51:51 UTC
+++ chrome/browser/ui/test/test_browser_dialog.cc
@@ -116,7 +116,7 @@ bool TestBrowserDialog::VerifyUi() {
 // TODO(https://crbug.com/958242) support Mac for pixel tests.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   dialog_widget->SetBlockCloseForTesting(true);
   // Deactivate before taking screenshot. Deactivated dialog pixel outputs
   // is more predictable than activated dialog.
