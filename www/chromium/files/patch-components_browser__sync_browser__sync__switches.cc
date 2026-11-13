--- components/browser_sync/browser_sync_switches.cc.orig	2026-11-11 14:44:17 UTC
+++ components/browser_sync/browser_sync_switches.cc
@@ -40,7 +40,7 @@ BASE_FEATURE(kMigrateOutOfSyncSetupIncompleteState,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableReadingListForMigratedUsers,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
