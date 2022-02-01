--- chrome/browser/download/download_prefs.cc.orig	2021-12-31 00:57:22 UTC
+++ chrome/browser/download/download_prefs.cc
@@ -70,7 +70,7 @@ namespace {
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -167,7 +167,7 @@ DownloadPrefs::DownloadPrefs(Profile* profile) : profi
                                 GetDefaultDownloadDirectoryForProfile()));
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
@@ -286,7 +286,7 @@ void DownloadPrefs::RegisterProfilePrefs(
                                  default_download_path);
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
@@ -420,7 +420,7 @@ bool DownloadPrefs::IsDownloadPathManaged() const {
 }
 
 bool DownloadPrefs::IsAutoOpenByUserUsed() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   if (ShouldOpenPdfInSystemReader())
     return true;
@@ -435,7 +435,7 @@ bool DownloadPrefs::IsAutoOpenEnabled(const GURL& url,
     return false;
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   if (base::FilePath::CompareEqualIgnoreCase(extension,
                                              FILE_PATH_LITERAL("pdf")) &&
@@ -490,7 +490,7 @@ void DownloadPrefs::DisableAutoOpenByUserBasedOnExtens
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
@@ -512,7 +512,7 @@ bool DownloadPrefs::ShouldOpenPdfInSystemReader() cons
 #endif
 
 void DownloadPrefs::ResetAutoOpenByUser() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   SetShouldOpenPdfInSystemReader(false);
 #endif
