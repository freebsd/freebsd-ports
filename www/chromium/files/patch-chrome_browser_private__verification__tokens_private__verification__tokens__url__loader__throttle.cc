--- chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -57,6 +57,10 @@ void PrivateVerificationTokensURLLoaderThrottle::WillS
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -110,6 +114,7 @@ void PrivateVerificationTokensURLLoaderThrottle::WillS
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -117,6 +122,10 @@ void PrivateVerificationTokensURLLoaderThrottle::WillR
     const network::mojom::URLResponseHead& response_head,
     bool* defer,
     network::HttpRequestHeadersUpdateParams* headers_update_params) {
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   if (headers_update_params) {
     headers_update_params->removed_headers.push_back(
         net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -131,12 +140,17 @@ void PrivateVerificationTokensURLLoaderThrottle::WillR
     token_id_.reset();
     redeemer_origin_.reset();
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillProcessResponse(
     const GURL& response_url,
     network::mojom::URLResponseHead* response_head,
     bool* defer) {
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   if (token_id_.has_value()) {
     if (pvt_service_ && response_head &&
         !response_head->pvt_token_removed_due_to_cookies) {
@@ -148,4 +162,5 @@ void PrivateVerificationTokensURLLoaderThrottle::WillP
     token_id_.reset();
     redeemer_origin_.reset();
   }
+#endif
 }
