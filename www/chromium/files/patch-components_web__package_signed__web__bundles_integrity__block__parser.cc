--- components/web_package/signed_web_bundles/integrity_block_parser.cc.orig	2026-09-25 15:26:43 UTC
+++ components/web_package/signed_web_bundles/integrity_block_parser.cc
@@ -4,17 +4,19 @@
 
 #include "components/web_package/signed_web_bundles/integrity_block_parser.h"
 
+#include <algorithm>
 #include <string>
-#include <string_view>
 #include <vector>
 
-#include "base/check.h"
-#include "base/containers/span.h"
+#include "base/containers/map_util.h"
 #include "base/functional/bind.h"
 #include "base/strings/stringprintf.h"
+#include "base/strings/to_string.h"
 #include "base/types/expected.h"
 #include "base/types/expected_macros.h"
 #include "components/cbor/reader.h"
+#include "components/cbor/writer.h"
+#include "components/web_package/mojom/web_bundle_parser.mojom-forward.h"
 #include "components/web_package/mojom/web_bundle_parser.mojom.h"
 #include "components/web_package/signed_web_bundles/constants.h"
 #include "components/web_package/signed_web_bundles/ecdsa_p256_public_key.h"
@@ -22,56 +24,11 @@
 #include "components/web_package/signed_web_bundles/ed25519_public_key.h"
 #include "components/web_package/signed_web_bundles/ed25519_signature.h"
 #include "components/web_package/signed_web_bundles/integrity_block_attributes.h"
-#include "components/web_package/signed_web_bundles/rust/signed_web_bundles_rust.h"
 #include "components/web_package/signed_web_bundles/signed_web_bundle_id.h"
 #include "components/web_package/signed_web_bundles/types.h"
 
 namespace web_package {
 
-namespace {
-
-using SignatureType = signed_web_bundles::rust::SignatureType::Tag;
-using signed_web_bundles::rust::parse_integrity_block;
-
-base::expected<mojom::BundleIntegrityBlockSignatureStackEntryPtr, std::string>
-CreateSignatureStackEntry(
-    const signed_web_bundles::rust::SignatureStackEntry& entry) {
-  auto parsed_sig = mojom::BundleIntegrityBlockSignatureStackEntry::New();
-
-  switch (entry.signature_type.tag) {
-    case SignatureType::Ed25519: {
-      ASSIGN_OR_RETURN(auto public_key,
-                       Ed25519PublicKey::Create(entry.public_key.to_span()));
-      ASSIGN_OR_RETURN(auto signature,
-                       Ed25519Signature::Create(entry.signature.to_span()));
-      parsed_sig->signature_info = mojom::SignatureInfo::NewEd25519(
-          mojom::SignatureInfoEd25519::New(public_key, signature));
-      break;
-    }
-    case SignatureType::EcdsaP256SHA256: {
-      ASSIGN_OR_RETURN(auto public_key,
-                       EcdsaP256PublicKey::Create(entry.public_key.to_span()));
-      ASSIGN_OR_RETURN(auto signature, EcdsaP256SHA256Signature::Create(
-                                           entry.signature.to_span()));
-      parsed_sig->signature_info = mojom::SignatureInfo::NewEcdsaP256Sha256(
-          mojom::SignatureInfoEcdsaP256SHA256::New(public_key, signature));
-      break;
-    }
-    case SignatureType::Unknown: {
-      parsed_sig->signature_info =
-          mojom::SignatureInfo::NewUnknown(mojom::SignatureInfoUnknown::New());
-      break;
-    }
-  }
-
-  parsed_sig->attributes_cbor =
-      BinaryData(entry.attributes_cbor.begin(), entry.attributes_cbor.end());
-
-  return parsed_sig;
-}
-
-}  // namespace
-
 IntegrityBlockParser::IntegrityBlockParser(
     mojom::BundleDataSource& data_source,
     WebBundleParser::ParseIntegrityBlockCallback callback)
@@ -103,37 +60,103 @@ void IntegrityBlockParser::OnIntegrityBlockRead(
     RunErrorCallback("Error reading the integrity block.");
     return;
   }
+  // This structure is built during parsing and returned by the final callback
+  mojom::BundleIntegrityBlockPtr integrity_block =
+      mojom::BundleIntegrityBlock::New();
 
-  const auto parse_res = parse_integrity_block(*data);
-  if (!parse_res.has_value()) {
-    const auto& error = parse_res.error();
-    RunErrorCallback(std::string(error.message.as_str()),
-                     error.is_version_error
-                         ? mojom::BundleParseErrorType::kVersionError
-                         : mojom::BundleParseErrorType::kFormatError);
+  size_t consumed_bytes = 0;
+  cbor::Reader::DecoderError error;
+  cbor::Reader::Config config;
+  config.num_bytes_consumed = &consumed_bytes;
+  config.error_code_out = &error;
+
+  // When config `bytes_consumed` are assigned the CBOR parser reads only to the
+  // end of a structure. It parses only Integrity Block even if Web Bundle part
+  // starts just after.
+  std::optional<cbor::Value> value = cbor::Reader::Read(*data, config);
+  if (!value) {
+    RunErrorCallback("Error parsing integrity block as CBOR: " +
+                     std::string(cbor::Reader::ErrorCodeToString(error)));
     return;
   }
+  integrity_block->size = consumed_bytes;
 
-  const auto& parsed_ib = *parse_res;
-  auto integrity_block = mojom::BundleIntegrityBlock::New();
-  integrity_block->size = parsed_ib.size;
+  if (!value->is_array()) {
+    RunErrorCallback("Integrity block is not a CBOR array.");
+    return;
+  }
 
-  const std::string_view web_bundle_id_str =
-      parsed_ib.web_bundle_id.to_string_view();
-  RETURN_IF_ERROR(
-      SignedWebBundleId::Create(web_bundle_id_str),
-      [&](std::string error) { RunErrorCallback(std::move(error)); });
+  const cbor::Value::ArrayValue& top_array = value->GetArray();
+  if (top_array.size() != kIntegrityBlockV2TopLevelArrayLength) {
+    RunErrorCallback(base::StringPrintf(
+        "Invalid integrity block array length: expected %u, got %zu.",
+        kIntegrityBlockV2TopLevelArrayLength, top_array.size()));
+    return;
+  }
 
-  integrity_block->attributes =
-      IntegrityBlockAttributes(std::string(web_bundle_id_str),
-                               BinaryData(parsed_ib.attributes_cbor.begin(),
-                                          parsed_ib.attributes_cbor.end()));
+  // 1. Magic bytes
+  if (!top_array[0].is_bytestring() ||
+      !std::ranges::equal(top_array[0].GetBytestring(),
+                          kIntegrityBlockMagicBytes)) {
+    RunErrorCallback("Unexpected magic bytes.");
+    return;
+  }
 
-  for (const auto& entry : parsed_ib.signature_stack) {
+  // 2. Version
+  if (!top_array[1].is_bytestring() ||
+      !std::ranges::equal(top_array[1].GetBytestring(),
+                          kIntegrityBlockV2VersionBytes)) {
+    RunErrorCallback("Unexpected version bytes.",
+                     mojom::BundleParseErrorType::kVersionError);
+    return;
+  }
+
+  // 3. Attributes
+  if (!top_array[2].is_map()) {
+    RunErrorCallback("Integrity block attributes must be a map.");
+    return;
+  }
+  const cbor::Value::MapValue& attributes_map = top_array[2].GetMap();
+  const cbor::Value* web_bundle_id =
+      base::FindOrNull(attributes_map, cbor::Value(kWebBundleIdAttributeName));
+  if (!web_bundle_id || !web_bundle_id->is_string()) {
+    RunErrorCallback(
+        "`webBundleId` integrity block attribute is missing or malformed.");
+    return;
+  }
+
+  // Check if web_bundle_id is correct
+  RETURN_IF_ERROR(SignedWebBundleId::Create(web_bundle_id->GetString()),
+                  [&](const std::string& error) { RunErrorCallback(error); });
+
+  BinaryData attributes_cbor = *cbor::Writer::Write(top_array[2]);
+  integrity_block->attributes = IntegrityBlockAttributes(
+      web_bundle_id->GetString(), std::move(attributes_cbor));
+
+  // 4. Signature Stack
+  if (!top_array[3].is_array()) {
+    RunErrorCallback("Signature stack must be an array.");
+    return;
+  }
+  const cbor::Value::ArrayValue& signatures = top_array[3].GetArray();
+  if (signatures.empty()) {
+    RunErrorCallback(
+        "The signature stack must contain at least one signature.");
+    return;
+  }
+
+  for (const auto& signature_info_raw : signatures) {
     ASSIGN_OR_RETURN(
-        auto parsed_sig, CreateSignatureStackEntry(entry),
-        [&](std::string error) { RunErrorCallback(std::move(error)); });
-    integrity_block->signature_stack.push_back(std::move(parsed_sig));
+        auto parsed_signature_info, ParseSignatureInfo(signature_info_raw),
+        [&](const std::string& error) { this->RunErrorCallback(error); });
+
+    if (integrity_block->signature_stack.empty() &&
+        parsed_signature_info->signature_info->is_unknown()) {
+      RunErrorCallback("Unknown cipher type of the first signature.");
+      return;
+    }
+    integrity_block->signature_stack.push_back(
+        std::move(parsed_signature_info));
   }
 
   std::move(complete_callback_)
@@ -141,13 +164,74 @@ void IntegrityBlockParser::OnIntegrityBlockRead(
                           std::move(integrity_block), nullptr));
 }
 
+base::expected<mojom::BundleIntegrityBlockSignatureStackEntryPtr, std::string>
+IntegrityBlockParser::ParseSignatureInfo(
+    const cbor::Value& signature_info_raw) {
+  if (!signature_info_raw.is_array() ||
+      signature_info_raw.GetArray().size() != 2) {
+    return base::unexpected(
+        "Each signature stack entry must contain exactly two elements.");
+  }
+
+  const cbor::Value::ArrayValue& signature_info_array =
+      signature_info_raw.GetArray();
+  if (!signature_info_array[0].is_map() ||
+      !signature_info_array[1].is_bytestring()) {
+    return base::unexpected("Malformed signature stack entry.");
+  }
+
+  mojom::BundleIntegrityBlockSignatureStackEntryPtr parsed_signature_info =
+      mojom::BundleIntegrityBlockSignatureStackEntry::New();
+  parsed_signature_info->attributes_cbor =
+      *cbor::Writer::Write(signature_info_array[0]);
+
+  const cbor::Value::MapValue& signature_attributes =
+      signature_info_array[0].GetMap();
+  const BinaryData& signature_bytes = signature_info_array[1].GetBytestring();
+
+  const cbor::Value* ed25519_key = base::FindOrNull(
+      signature_attributes, cbor::Value(kEd25519PublicKeyAttributeName));
+  const cbor::Value* ecdsa_key = base::FindOrNull(
+      signature_attributes, cbor::Value(kEcdsaP256PublicKeyAttributeName));
+
+  if (ed25519_key && ecdsa_key) {
+    return base::unexpected("Multiple key types for one signature.");
+  } else if (ed25519_key && !ed25519_key->is_bytestring()) {
+    return base::unexpected("Invalid ED25519 key.");
+  } else if (ecdsa_key && !ecdsa_key->is_bytestring()) {
+    return base::unexpected("Invalid ECDSA key.");
+
+  } else if (ed25519_key && ed25519_key->is_bytestring()) {
+    ASSIGN_OR_RETURN(auto public_key,
+                     Ed25519PublicKey::Create(ed25519_key->GetBytestring()));
+    ASSIGN_OR_RETURN(auto signature, Ed25519Signature::Create(signature_bytes));
+    parsed_signature_info->signature_info = mojom::SignatureInfo::NewEd25519(
+        mojom::SignatureInfoEd25519::New(public_key, signature));
+
+  } else if (ecdsa_key && ecdsa_key->is_bytestring()) {
+    ASSIGN_OR_RETURN(auto public_key,
+                     EcdsaP256PublicKey::Create(ecdsa_key->GetBytestring()));
+    ASSIGN_OR_RETURN(auto signature,
+                     EcdsaP256SHA256Signature::Create(signature_bytes));
+    parsed_signature_info->signature_info =
+        mojom::SignatureInfo::NewEcdsaP256Sha256(
+            mojom::SignatureInfoEcdsaP256SHA256::New(public_key, signature));
+
+  } else {
+    parsed_signature_info->signature_info =
+        mojom::SignatureInfo::NewUnknown(mojom::SignatureInfoUnknown::New());
+  }
+
+  return parsed_signature_info;
+}
+
 void IntegrityBlockParser::RunErrorCallback(
-    std::string message,
+    const std::string& message,
     mojom::BundleParseErrorType error_type) {
   std::move(complete_callback_)
-      .Run(base::BindOnce(std::move(result_callback_), nullptr,
-                          mojom::BundleIntegrityBlockParseError::New(
-                              error_type, std::move(message))));
+      .Run(base::BindOnce(
+          std::move(result_callback_), nullptr,
+          mojom::BundleIntegrityBlockParseError::New(error_type, message)));
 }
 
 }  // namespace web_package
