--- chrome/browser/download/download_prefs.h.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/download/download_prefs.h
@@ -117,7 +117,7 @@ class DownloadPrefs {
   // Disables auto-open based on file extension.
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
@@ -176,7 +176,7 @@ class DownloadPrefs {
 
   std::unique_ptr<policy::URLBlocklist> auto_open_allowed_by_urls_;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   bool should_open_pdf_in_system_reader_;
 #endif
