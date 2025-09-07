--- chrome/browser/sync/chrome_sync_controller_builder.cc.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/sync/chrome_sync_controller_builder.cc
@@ -304,7 +304,7 @@ ChromeSyncControllerBuilder::Build(syncer::SyncService
 #if BUILDFLAG(ENABLE_SPELLCHECK)
     // Chrome prefers OS provided spell checkers where they exist. So only sync
     // the custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (spellcheck_service_.value()) {
       controllers.push_back(
