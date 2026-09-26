--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -725,6 +725,7 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
   if (remove_mask & constants::DATA_TYPE_PRIVATE_VERIFICATION_TOKENS) {
     if (base::FeatureList::IsEnabled(
             net::features::kEnablePrivateVerificationTokens)) {
+#if !BUILDFLAG(IS_BSD)
       if (auto* pvt_service =
               PrivateVerificationTokensServiceFactory::GetForProfile(
                   profile_)) {
@@ -741,6 +742,9 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
               filter_builder->BuildStorageKeyFilter(), std::move(done_closure));
         }
       }
+#else
+      LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
     }
   }
 
