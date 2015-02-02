--- chrome/common/pref_names.cc.orig	2015-01-21 20:28:16 UTC
+++ chrome/common/pref_names.cc
@@ -895,7 +895,7 @@
 // supervised users.
 const char kRecordHistory[] = "settings.history_recorded";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1425,7 +1425,7 @@
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
