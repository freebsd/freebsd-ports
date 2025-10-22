--- components/sync/service/sync_service_impl.cc.orig	2025-10-21 16:57:35 UTC
+++ components/sync/service/sync_service_impl.cc
@@ -1328,7 +1328,7 @@ void SyncServiceImpl::ReconfigureDataTypesDueToCrypto(
 
 void SyncServiceImpl::PassphraseTypeChanged(PassphraseType passphrase_type) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
-#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // If kReplaceSyncPromosWithSignInPromos is enabled, new users with custom
   // passphrase should have kAutofill disabled upon the initial sign-in. This is
   // done to prevent confusion, as addresses are NOT encrypted by the custom
