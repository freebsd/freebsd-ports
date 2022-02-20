--- chrome/browser/download/download_prefs.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/download/download_prefs.h
@@ -122,7 +122,7 @@ class DownloadPrefs {
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -181,7 +181,7 @@ class DownloadPrefs {
   std::unique_ptr<policy::URLBlocklist> auto_open_allowed_by_urls_;
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
