--- chrome/browser/download/download_prefs.cc.orig	2015-01-24 21:51:37 UTC
+++ chrome/browser/download/download_prefs.cc
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
@@ -205,7 +205,7 @@
       prefs::kSaveFileDefaultDirectory,
       default_download_path,
       user_prefs::PrefRegistrySyncable::UNSYNCABLE_PREF);
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   registry->RegisterBooleanPref(
       prefs::kOpenPdfDownloadInSystemReader,
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
@@ -333,7 +333,7 @@
   SaveAutoOpenState();
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
@@ -355,7 +355,7 @@
 #endif
 
 void DownloadPrefs::ResetAutoOpen() {
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   SetShouldOpenPdfInSystemReader(false);
 #endif
