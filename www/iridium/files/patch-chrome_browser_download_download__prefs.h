--- chrome/browser/download/download_prefs.h.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/download/download_prefs.h
@@ -102,7 +102,7 @@ class DownloadPrefs {
   // Disables auto-open based on file extension.
   void DisableAutoOpenBasedOnExtension(const base::FilePath& file_name);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -150,7 +150,7 @@ class DownloadPrefs {
                    AutoOpenCompareFunctor> AutoOpenSet;
   AutoOpenSet auto_open_;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
