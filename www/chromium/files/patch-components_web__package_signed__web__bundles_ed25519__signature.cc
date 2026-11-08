--- components/web_package/signed_web_bundles/ed25519_signature.cc.orig	2026-09-25 15:26:43 UTC
+++ components/web_package/signed_web_bundles/ed25519_signature.cc
@@ -7,7 +7,6 @@
 #include <algorithm>
 
 #include "base/strings/stringprintf.h"
-#include "components/web_package/signed_web_bundles/rust/signed_web_bundles_rust.h"
 #include "third_party/boringssl/src/include/openssl/curve25519.h"
 
 namespace web_package {
@@ -43,8 +42,11 @@ Ed25519Signature::Ed25519Signature(std::array<uint8_t,
 [[nodiscard]] bool Ed25519Signature::Verify(
     base::span<const uint8_t> message,
     const Ed25519PublicKey& public_key) const {
-  return signed_web_bundles::rust::verify_ed25519_signature(public_key.bytes(),
-                                                            bytes(), message);
+  const std::array<uint8_t, ED25519_PUBLIC_KEY_LEN>& public_key_bytes =
+      public_key.bytes();
+  const std::array<uint8_t, ED25519_SIGNATURE_LEN>& signature_bytes = bytes();
+  return ED25519_verify(message.data(), message.size(), signature_bytes.data(),
+                        public_key_bytes.data());
 }
 
 }  // namespace web_package
