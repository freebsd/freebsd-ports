--- components/device_signals/core/common/signals_features.h.orig	2025-03-09 21:38:10 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -14,7 +14,7 @@ namespace enterprise_signals::features {
 BASE_DECLARE_FEATURE(kAllowClientCertificateReportingForUsers);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
