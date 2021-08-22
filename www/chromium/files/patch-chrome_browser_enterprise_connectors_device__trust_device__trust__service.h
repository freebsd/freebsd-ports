--- chrome/browser/enterprise/connectors/device_trust/device_trust_service.h.orig	2021-07-19 18:45:08 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service.h
@@ -41,9 +41,9 @@ class DeviceTrustService : public KeyedService {
       std::unique_ptr<DeviceTrustSignalReporter> reporter);
   using SignalReportCallback = base::OnceCallback<void(bool)>;
   void SetSignalReportCallbackForTesting(SignalReportCallback cb);
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   std::string GetAttestationCredentialForTesting() const;
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   // Starts flow that actually builds a response. This method is called
   // from a non_UI thread.
