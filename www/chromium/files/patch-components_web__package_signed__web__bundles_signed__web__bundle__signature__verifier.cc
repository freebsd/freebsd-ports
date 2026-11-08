--- components/web_package/signed_web_bundles/signed_web_bundle_signature_verifier.cc.orig	2026-09-25 15:26:43 UTC
+++ components/web_package/signed_web_bundles/signed_web_bundle_signature_verifier.cc
@@ -20,14 +20,17 @@
 #include "base/task/thread_pool.h"
 #include "base/types/expected.h"
 #include "base/types/expected_macros.h"
+#include "components/cbor/values.h"
+#include "components/cbor/writer.h"
+#include "components/web_package/signed_web_bundles/constants.h"
 #include "components/web_package/signed_web_bundles/identity_validator.h"
 #include "components/web_package/signed_web_bundles/integrity_block_parser.h"
-#include "components/web_package/signed_web_bundles/rust/signed_web_bundles_rust.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_id.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_integrity_block.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_signature_stack.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_signature_stack_entry.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_utils.h"
+#include "crypto/hash.h"
 #include "third_party/abseil-cpp/absl/functional/overload.h"
 #include "third_party/boringssl/src/include/openssl/sha.h"
 
@@ -37,10 +40,32 @@ namespace {
 
 std::vector<uint8_t> CreateIntegrityBlockCbor(
     const SignedWebBundleIntegrityBlock& integrity_block) {
-  auto ib_cbor_rust =
-      signed_web_bundles::rust::create_empty_integrity_block_cbor(
-          integrity_block.attributes_cbor());
-  return std::vector<uint8_t>(ib_cbor_rust.begin(), ib_cbor_rust.end());
+  // This function looks like it should use a cbor::Value::ArrayValue to build
+  // the outer array, but it can't: one of the elements is a pre-encoded CBOR
+  // value which we can't safely decode because it's untrusted input. This is
+  // obviously undesirable, because there's no guarantee at all that the
+  // pre-encoded value is actually valid CBOR.
+  //
+  // TODO(https://crbug.com/454485901): once there's a memory-safe CBOR parser,
+  // re-parse the pre-encoded value, then re-encode it here instead of
+  // constructing a CBOR array by hand so that we're guaranteed that the result
+  // of this function is valid.
+  std::vector<uint8_t> ib_cbor;
+
+  // 0x84 is the encoding byte for an array of length 4.
+  ib_cbor.push_back(0x84);
+  base::Extend(ib_cbor,
+               *cbor::Writer::Write(cbor::Value(kIntegrityBlockMagicBytes)));
+  base::Extend(ib_cbor, *cbor::Writer::Write(
+                            cbor::Value(kIntegrityBlockV2VersionBytes)));
+  // We cannot parse `attributes().cbor()` back to a cbor::Value as they
+  // technically represent untrusted input.
+  base::Extend(ib_cbor, integrity_block.attributes_cbor());
+  // Encode an empty signature array.
+  base::Extend(ib_cbor,
+               *cbor::Writer::Write(cbor::Value(cbor::Value::ArrayValue())));
+
+  return ib_cbor;
 }
 
 base::expected<void, SignedWebBundleSignatureVerifier::Error>
@@ -104,7 +129,7 @@ SignedWebBundleSignatureVerifier::CalculateHashOfUnsig
     return base::unexpected(base::File::ErrorToString(file.GetLastFileError()));
   }
 
-  signed_web_bundles::rust::Sha512Hasher hasher;
+  crypto::hash::Hasher hash(crypto::hash::kSha512);
 
   // Calculate the hash of the Signed Web Bundle excluding its integrity block.
   // The file might be too big to read it into memory all at once, which is why
@@ -121,14 +146,15 @@ SignedWebBundleSignatureVerifier::CalculateHashOfUnsig
           base::File::ErrorToString(file.GetLastFileError()));
     }
     data.resize(*bytes_read);
-    hasher.update(data);
+    hash.Update(data);
 
     if (!base::CheckAdd(offset, *bytes_read).AssignIfValid(&offset)) {
       return base::unexpected("The Signed Web Bundle is too large.");
     }
   }
 
-  SHA512Digest digest = std::move(hasher).finish();
+  SHA512Digest digest;
+  hash.Finish(digest);
   return digest;
 }
 
