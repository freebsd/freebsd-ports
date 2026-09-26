--- chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -52,7 +52,10 @@ void PrivateVerificationTokensURLLoaderThrottle::WillS
       !pvt_service_) {
     return;
   }
-
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -83,6 +86,7 @@ void PrivateVerificationTokensURLLoaderThrottle::WillS
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -96,7 +100,7 @@ void PrivateVerificationTokensURLLoaderThrottle::WillR
   }
   if (token_id_.has_value()) {
     if (pvt_service_ && !response_head.pvt_token_removed_due_to_cookies) {
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
   }
@@ -109,7 +113,7 @@ void PrivateVerificationTokensURLLoaderThrottle::WillP
   if (token_id_.has_value()) {
     if (pvt_service_ && response_head &&
         !response_head->pvt_token_removed_due_to_cookies) {
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
   }
