--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2022-10-29 17:50:56 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -178,7 +178,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
   // Delete the local undecryptable copy when this is MacOS only.
 #if BUILDFLAG(IS_MAC)
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kSyncUndecryptablePasswordsLinux);
 #else
@@ -187,7 +187,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
