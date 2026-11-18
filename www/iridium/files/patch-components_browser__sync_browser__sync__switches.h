--- components/browser_sync/browser_sync_switches.h.orig	2026-11-17 21:17:00 UTC
+++ components/browser_sync/browser_sync_switches.h
@@ -58,7 +58,7 @@ BASE_DECLARE_FEATURE(kForceMigrateNoopForDebugging);
 BASE_DECLARE_FEATURE(kMigrateOutOfSyncSetupIncompleteState);
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, users who were migrated from syncing to signed-in before the
 // migration carried over the Reading List toggle get Reading List enabled at
 // browser startup (see crbug.com/568406887).
