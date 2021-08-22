--- chrome/browser/enterprise/connectors/device_trust/attestation_service.cc.orig	2021-07-28 07:35:48 UTC
+++ chrome/browser/enterprise/connectors/device_trust/attestation_service.cc
@@ -18,10 +18,10 @@
 namespace enterprise_connectors {
 
 AttestationService::AttestationService() {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   key_pair_ = std::make_unique<enterprise_connectors::DeviceTrustKeyPair>();
   key_pair_->Init();
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 }
 
 AttestationService::~AttestationService() = default;
@@ -71,11 +71,11 @@ std::string AttestationService::ProtobufChallengeToJso
   base::Base64Encode(challenge_response, &encoded);
   signed_data.SetKey("data", base::Value(encoded));
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   std::string signature;
   key_pair_->GetSignatureInBase64(challenge_response, &signature);
   signed_data.SetKey("signature", base::Value(signature));
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   base::Value dict(base::Value::Type::DICTIONARY);
   dict.SetKey("challengeResponse", std::move(signed_data));
@@ -85,11 +85,11 @@ std::string AttestationService::ProtobufChallengeToJso
   return json;
 }
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 std::string AttestationService::ExportPEMPublicKey() {
   return key_pair_->ExportPEMPublicKey();
 }
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
 void AttestationService::SignEnterpriseChallenge(
     const SignEnterpriseChallengeRequest& request,
@@ -110,9 +110,9 @@ void AttestationService::SignEnterpriseChallengeTask(
 
   KeyInfo key_info;
   // Set the public key so VA can verify the client.
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   key_info.set_signed_public_key_and_challenge(ExportPEMPublicKey());
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   ChallengeResponse response_pb;
   *response_pb.mutable_challenge() = signed_challenge;
@@ -135,12 +135,12 @@ void AttestationService::SignEnterpriseChallengeTask(
 bool AttestationService::SignChallengeData(const std::string& data,
                                            std::string* response) {
   std::string signature;
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   if (!key_pair_->GetSignatureInBase64(data, &signature)) {
     LOG(ERROR) << __func__ << ": Failed to sign data.";
     return false;
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   SignedData signed_data;
   signed_data.set_data(data);
   signed_data.set_signature(signature);
