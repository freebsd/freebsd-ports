--- chrome/browser/ui/test/test_browser_dialog.cc.orig	2020-07-13 09:23:32 UTC
+++ chrome/browser/ui/test/test_browser_dialog.cc
@@ -114,7 +114,7 @@ bool TestBrowserDialog::VerifyUi() {
 
   views::Widget* dialog_widget = *(added.begin());
 // TODO(https://crbug.com/958242) support Mac for pixel tests.
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   dialog_widget->SetBlockCloseForTesting(true);
   // Deactivate before taking screenshot. Deactivated dialog pixel outputs
   // is more predictable than activated dialog.
