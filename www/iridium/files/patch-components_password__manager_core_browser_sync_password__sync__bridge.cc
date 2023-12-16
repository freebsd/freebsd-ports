--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2023-11-22 14:00:11 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -197,7 +197,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
