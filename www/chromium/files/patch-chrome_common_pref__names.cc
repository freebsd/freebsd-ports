--- chrome/common/pref_names.cc.orig	2016-05-11 19:02:17 UTC
+++ chrome/common/pref_names.cc
@@ -885,7 +885,7 @@ const char kForceYouTubeSafetyMode[] = "
 // supervised users.
 const char kRecordHistory[] = "settings.history_recorded";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1348,7 +1348,7 @@ const char kDownloadDefaultDirectory[] =
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
