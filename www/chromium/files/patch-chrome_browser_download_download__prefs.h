--- chrome/browser/download/download_prefs.h.orig	2020-09-08 19:13:59 UTC
+++ chrome/browser/download/download_prefs.h
@@ -114,7 +114,7 @@ class DownloadPrefs {
   // Disables auto-open based on file extension.
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -172,7 +172,7 @@ class DownloadPrefs {
 
   std::unique_ptr<policy::URLBlacklist> auto_open_allowed_by_urls_;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
