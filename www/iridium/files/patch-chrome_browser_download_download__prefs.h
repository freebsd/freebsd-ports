--- chrome/browser/download/download_prefs.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/download/download_prefs.h
@@ -118,7 +118,7 @@ class DownloadPrefs {
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -182,7 +182,7 @@ class DownloadPrefs {
   std::unique_ptr<policy::URLBlocklist> auto_open_allowed_by_urls_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
