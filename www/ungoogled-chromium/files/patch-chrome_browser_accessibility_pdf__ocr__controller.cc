--- chrome/browser/accessibility/pdf_ocr_controller.cc.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/accessibility/pdf_ocr_controller.cc
@@ -111,7 +111,7 @@ void AnnounceToScreenReader(const int message_id) {
 // TODO(crbug.com/1442928): Sending announcements results in a failure in
 // `AuraLinuxAccessibilityInProcessBrowserTest::IndexInParentWithModal` and
 // flaky fail when running Chrome.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   const Browser* browser = BrowserList::GetInstance()->GetLastActive();
   if (!browser) {
     VLOG(2) << "Browser is not ready to announce";
