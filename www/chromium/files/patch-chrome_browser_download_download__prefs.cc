--- chrome/browser/download/download_prefs.cc.orig	2020-09-08 19:13:59 UTC
+++ chrome/browser/download/download_prefs.cc
@@ -67,7 +67,7 @@ namespace {
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -172,7 +172,7 @@ DownloadPrefs::DownloadPrefs(Profile* profile) : profi
                                 GetDefaultDownloadDirectoryForProfile()));
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
 #endif
@@ -299,7 +299,7 @@ void DownloadPrefs::RegisterProfilePrefs(
                                  default_download_path);
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
 #if defined(OS_ANDROID)
@@ -417,7 +417,7 @@ bool DownloadPrefs::IsDownloadPathManaged() const {
 }
 
 bool DownloadPrefs::IsAutoOpenByUserUsed() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (ShouldOpenPdfInSystemReader())
     return true;
 #endif
@@ -431,7 +431,7 @@ bool DownloadPrefs::IsAutoOpenEnabled(const GURL& url,
     return false;
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (base::FilePath::CompareEqualIgnoreCase(extension,
                                              FILE_PATH_LITERAL("pdf")) &&
       ShouldOpenPdfInSystemReader())
@@ -481,7 +481,7 @@ void DownloadPrefs::DisableAutoOpenByUserBasedOnExtens
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
     return;
@@ -502,7 +502,7 @@ bool DownloadPrefs::ShouldOpenPdfInSystemReader() cons
 #endif
 
 void DownloadPrefs::ResetAutoOpenByUser() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   SetShouldOpenPdfInSystemReader(false);
 #endif
   auto_open_by_user_.clear();
