--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -731,6 +731,7 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
   if (remove_mask & constants::DATA_TYPE_PRIVATE_VERIFICATION_TOKENS) {
     if (base::FeatureList::IsEnabled(
             net::features::kEnablePrivateVerificationTokens)) {
+#if !BUILDFLAG(IS_BSD)
       if (auto* pvt_service =
               PrivateVerificationTokensServiceFactory::GetForProfile(
                   profile_)) {
@@ -747,6 +748,9 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
               filter_builder->BuildStorageKeyFilter(), std::move(done_closure));
         }
       }
+#else
+      LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
     }
   }
 
