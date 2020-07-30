--- chrome/browser/download/download_prefs.h.orig	2020-07-07 21:57:32 UTC
+++ chrome/browser/download/download_prefs.h
@@ -110,7 +110,7 @@ class DownloadPrefs {
   // Disables auto-open based on file extension.
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -167,7 +167,7 @@ class DownloadPrefs {
 
   std::unique_ptr<policy::URLBlacklist> auto_open_allowed_by_urls_;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
