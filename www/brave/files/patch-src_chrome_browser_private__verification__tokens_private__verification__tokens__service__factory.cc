--- src/chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc
@@ -108,6 +108,10 @@ PrivateVerificationTokensServiceFactory:
           net::features::kEnablePrivateVerificationTokens)) {
     return nullptr;
   }
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return nullptr;
+#else
   Profile* profile = Profile::FromBrowserContext(context);
   CHECK(profile);
   auto service = PrivateVerificationTokensService::Create(
@@ -119,6 +123,7 @@ PrivateVerificationTokensServiceFactory:
     }
   }
   return service;
+#endif
 }
 
 bool PrivateVerificationTokensServiceFactory::
