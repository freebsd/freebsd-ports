--- chrome/browser/download/download_prefs.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/download/download_prefs.cc
@@ -13,6 +13,7 @@
 #include "base/callback_helpers.h"
 #include "base/check.h"
 #include "base/cxx17_backports.h"
+#include "base/command_line.h"
 #include "base/feature_list.h"
 #include "base/files/file_util.h"
 #include "base/no_destructor.h"
@@ -60,6 +61,8 @@
 #include "chrome/browser/ui/pdf/adobe_reader_info_win.h"
 #endif
 
+#include "sandbox/policy/switches.h"
+
 using content::BrowserContext;
 using content::BrowserThread;
 using content::DownloadManager;
@@ -70,7 +73,7 @@ namespace {
 // Consider downloads 'dangerous' if they go to the home directory on Linux and
 // to the desktop on any platform.
 bool DownloadPathIsDangerous(const base::FilePath& download_path) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::FilePath home_dir = base::GetHomeDir();
   if (download_path == home_dir) {
     return true;
@@ -168,7 +171,7 @@ DownloadPrefs::DownloadPrefs(Profile* profile) : profi
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   should_open_pdf_in_system_reader_ =
       prefs->GetBoolean(prefs::kOpenPdfDownloadInSystemReader);
 #endif
@@ -287,7 +290,7 @@ void DownloadPrefs::RegisterProfilePrefs(
   registry->RegisterFilePathPref(prefs::kSaveFileDefaultDirectory,
                                  default_download_path);
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kOpenPdfDownloadInSystemReader, false);
 #endif
 #if defined(OS_ANDROID)
@@ -421,7 +424,7 @@ bool DownloadPrefs::IsDownloadPathManaged() const {
 
 bool DownloadPrefs::IsAutoOpenByUserUsed() const {
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   if (ShouldOpenPdfInSystemReader())
     return true;
 #endif
@@ -436,7 +439,7 @@ bool DownloadPrefs::IsAutoOpenEnabled(const GURL& url,
   DCHECK(extension[0] == base::FilePath::kExtensionSeparator);
   extension.erase(0, 1);
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   if (base::FilePath::CompareEqualIgnoreCase(extension,
                                              FILE_PATH_LITERAL("pdf")) &&
       ShouldOpenPdfInSystemReader())
@@ -491,7 +494,7 @@ void DownloadPrefs::DisableAutoOpenByUserBasedOnExtens
 }
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
 void DownloadPrefs::SetShouldOpenPdfInSystemReader(bool should_open) {
   if (should_open_pdf_in_system_reader_ == should_open)
     return;
@@ -513,7 +516,7 @@ bool DownloadPrefs::ShouldOpenPdfInSystemReader() cons
 
 void DownloadPrefs::ResetAutoOpenByUser() {
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   SetShouldOpenPdfInSystemReader(false);
 #endif
   auto_open_by_user_.clear();
@@ -630,9 +633,13 @@ base::FilePath DownloadPrefs::SanitizeDownloadTargetPa
   // Fall back to the default download directory for all other paths.
   return GetDefaultDownloadDirectoryForProfile();
 #else
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+
   // If the stored download directory is an absolute path, we presume it's
   // correct; there's not really much more validation we can do here.
-  if (path.IsAbsolute())
+  if (command_line->HasSwitch(sandbox::policy::switches::kDisableUnveil) && path.IsAbsolute())
     return path;
 
   // When the default download directory is *not* an absolute path, we use the
