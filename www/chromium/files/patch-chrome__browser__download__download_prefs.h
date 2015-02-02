--- chrome/browser/download/download_prefs.h.orig	2015-01-24 21:53:47 UTC
+++ chrome/browser/download/download_prefs.h
@@ -73,7 +73,7 @@
   // Disables auto-open based on file extension.
   void DisableAutoOpenBasedOnExtension(const base::FilePath& file_name);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
@@ -105,7 +105,7 @@
                    AutoOpenCompareFunctor> AutoOpenSet;
   AutoOpenSet auto_open_;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   bool should_open_pdf_in_system_reader_;
 #endif
