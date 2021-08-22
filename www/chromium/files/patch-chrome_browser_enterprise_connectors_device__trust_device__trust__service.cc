--- chrome/browser/enterprise/connectors/device_trust/device_trust_service.cc.orig	2021-07-19 18:45:08 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service.cc
@@ -82,12 +82,12 @@ void DeviceTrustService::OnReporterInitialized(bool su
 
   DeviceTrustReportEvent report;
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   auto* credential = report.mutable_attestation_credential();
   credential->set_format(
       DeviceTrustReportEvent::Credential::EC_NID_X9_62_PRIME256V1_PUBLIC_DER);
   credential->set_credential(attestation_service_->ExportPEMPublicKey());
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   reporter_->SendReport(&report, std::move(signal_report_callback_));
 }
@@ -117,11 +117,11 @@ void DeviceTrustService::SetSignalReportCallbackForTes
       base::Unretained(this), std::move(cb));
 }
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 std::string DeviceTrustService::GetAttestationCredentialForTesting() const {
   return attestation_service_->ExportPEMPublicKey();
 }
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
 void DeviceTrustService::BuildChallengeResponse(const std::string& challenge,
                                                 AttestationCallback callback) {
