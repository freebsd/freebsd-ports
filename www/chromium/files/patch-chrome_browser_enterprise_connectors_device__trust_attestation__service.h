--- chrome/browser/enterprise/connectors/device_trust/attestation_service.h.orig	2021-07-28 07:36:46 UTC
+++ chrome/browser/enterprise/connectors/device_trust/attestation_service.h
@@ -94,9 +94,9 @@ class AttestationService {
       AttestationCallback callback,
       const std::string& challenge_response_proto);
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   std::unique_ptr<enterprise_connectors::DeviceTrustKeyPair> key_pair_;
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   GoogleKeys google_keys_;
   base::WeakPtrFactory<AttestationService> weak_factory_{this};
