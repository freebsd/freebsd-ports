--- chrome/browser/download/download_prefs.cc.orig	2015-07-15 16:29:57.000000000 -0400
+++ chrome/browser/download/download_prefs.cc	2015-07-21 21:27:54.085299000 -0400
@@ -51,7 +51,7 @@
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -131,7 +131,7 @@
                  GetDefaultDownloadDirectoryForProfile()));
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
@@ -208,7 +208,7 @@
                                  default_download_path);
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
@@ -286,7 +286,7 @@
 }
 
 bool DownloadPrefs::IsAutoOpenUsed() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
       (defined(OS_MACOSX) && !defined(OS_IOS))
   if (ShouldOpenPdfInSystemReader())
     return true;
@@ -301,7 +301,7 @@
     return false;
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   if (extension == FILE_PATH_LITERAL("pdf") && ShouldOpenPdfInSystemReader())
     return true;
@@ -335,7 +335,7 @@
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
@@ -357,7 +357,7 @@
 #endif
 
 void DownloadPrefs::ResetAutoOpen() {
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   SetShouldOpenPdfInSystemReader(false);
 #endif
