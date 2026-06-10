--- chrome/browser/signin/signin_util.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/signin/signin_util.h
@@ -206,7 +206,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
     const syncer::SyncService* sync_service,
     const syncer::UserSelectableTypeSet& types);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // True if the user has explicitly disabled syncing history, tabs or saved tab
 // groups through the settings. The primary account must be set (this crashes
 // otherwise).
