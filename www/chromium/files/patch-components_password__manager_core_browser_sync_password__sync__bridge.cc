--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2022-02-28 16:54:41 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -181,7 +181,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
   // Delete the local undecryptable copy when this is MacOS only.
 #if BUILDFLAG(IS_MAC)
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kSyncUndecryptablePasswordsLinux);
 #else
