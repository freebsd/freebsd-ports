--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2024-06-17 12:56:06 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -196,7 +196,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
