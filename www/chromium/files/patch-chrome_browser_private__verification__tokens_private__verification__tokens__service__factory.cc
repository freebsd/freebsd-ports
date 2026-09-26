--- chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc
@@ -102,6 +102,10 @@ PrivateVerificationTokensServiceFactory::BuildServiceI
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
@@ -113,6 +117,7 @@ PrivateVerificationTokensServiceFactory::BuildServiceI
     }
   }
   return service;
+#endif
 }
 
 bool PrivateVerificationTokensServiceFactory::
