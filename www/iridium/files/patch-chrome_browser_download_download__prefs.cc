--- chrome/browser/download/download_prefs.cc.orig	2017-04-24 14:40:26 UTC
+++ chrome/browser/download/download_prefs.cc
@@ -56,7 +56,7 @@ namespace {
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -136,7 +136,7 @@ DownloadPrefs::DownloadPrefs(Profile* pr
                  GetDefaultDownloadDirectoryForProfile()));
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
 #endif
@@ -213,7 +213,7 @@ void DownloadPrefs::RegisterProfilePrefs
                                  default_download_path);
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
 }
@@ -290,7 +290,7 @@ bool DownloadPrefs::IsDownloadPathManage
 }
 
 bool DownloadPrefs::IsAutoOpenUsed() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (ShouldOpenPdfInSystemReader())
     return true;
 #endif
@@ -304,7 +304,7 @@ bool DownloadPrefs::IsAutoOpenEnabledBas
     return false;
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (extension == FILE_PATH_LITERAL("pdf") && ShouldOpenPdfInSystemReader())
     return true;
 #endif
@@ -338,7 +338,7 @@ void DownloadPrefs::DisableAutoOpenBased
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
     return;
@@ -359,7 +359,7 @@ bool DownloadPrefs::ShouldOpenPdfInSyste
 #endif
 
 void DownloadPrefs::ResetAutoOpen() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   SetShouldOpenPdfInSystemReader(false);
 #endif
   auto_open_.clear();
