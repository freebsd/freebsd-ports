--- components/sync/base/pref_names.h.orig	2026-11-19 12:25:27 UTC
+++ components/sync/base/pref_names.h
@@ -141,7 +141,7 @@ inline constexpr char kMigrateExtensionsFromLocalToAcc
 inline constexpr char kMigrateThemeFromLocalToAccount[] =
     "sync.migrate_theme_from_local_to_account";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Whether SyncPrefs::MigrateGlobalDataTypePrefsToAccount() ran with the Reading
 // List toggle included (see crbug.com/568406887).
 inline constexpr char kReadingListPrefMigratedToAccount[] =
