--- chrome/browser/download/download_prefs.cc.orig	2017-12-15 02:04:08.000000000 +0100
+++ chrome/browser/download/download_prefs.cc	2017-12-24 01:04:45.230590000 +0100
@@ -56,7 +56,7 @@
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -135,7 +135,7 @@
                                 GetDefaultDownloadDirectoryForProfile()));
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
 #endif
@@ -219,7 +219,7 @@
                                  default_download_path);
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
 }
@@ -302,7 +302,7 @@
 }
 
 bool DownloadPrefs::IsAutoOpenUsed() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (ShouldOpenPdfInSystemReader())
     return true;
 #endif
@@ -316,7 +316,7 @@
     return false;
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (base::FilePath::CompareEqualIgnoreCase(extension,
                                              FILE_PATH_LITERAL("pdf")) &&
       ShouldOpenPdfInSystemReader())
@@ -353,7 +353,7 @@
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
     return;
@@ -374,7 +374,7 @@
 #endif
 
 void DownloadPrefs::ResetAutoOpen() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   SetShouldOpenPdfInSystemReader(false);
 #endif
   auto_open_.clear();
