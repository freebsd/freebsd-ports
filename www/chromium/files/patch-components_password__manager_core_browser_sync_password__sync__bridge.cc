--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2023-01-11 09:17:16 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -185,7 +185,7 @@ bool IsCredentialPhished(const sync_pb::PasswordSpecif
 // merge.
 bool ShouldRecoverPasswordsDuringMerge() {
   // Delete the local undecryptable copy when this is MacOS only.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -193,7 +193,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
