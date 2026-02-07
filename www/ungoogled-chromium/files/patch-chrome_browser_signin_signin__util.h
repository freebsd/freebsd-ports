--- chrome/browser/signin/signin_util.h.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/signin/signin_util.h
@@ -207,7 +207,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
     const syncer::SyncService* sync_service,
     const syncer::UserSelectableTypeSet& types);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // True if the user has explicitly disabled syncing history, tabs or saved tab
 // groups through the settings. The primary account must be set (this crashes
 // otherwise).
