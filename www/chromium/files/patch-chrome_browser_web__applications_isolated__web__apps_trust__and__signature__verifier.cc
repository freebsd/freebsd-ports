--- chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc
@@ -32,6 +32,8 @@ void CheckTrustAndSignatures(
         void(base::expected<
              std::optional<web_package::SignedWebBundleIntegrityBlock>,
              std::string>)> callback) {
+// XXX crubit
+#if 0
   RETURN_IF_ERROR(IsolatedWebAppTrustChecker::IsOperationAllowed(
                       *profile, web_bundle_id, location.dev_mode(), operation),
                   [&](const std::string& error) {
@@ -61,6 +63,7 @@ void CheckTrustAndSignatures(
             std::move(callback).Run(base::ok(std::nullopt));
           }},
       location.variant());
+#endif
 }
 
 void CheckTrustAndSignatures(
