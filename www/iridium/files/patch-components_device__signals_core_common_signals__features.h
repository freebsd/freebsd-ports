--- components/device_signals/core/common/signals_features.h.orig	2025-09-11 13:19:19 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -33,7 +33,7 @@ bool IsBrowserSignalsReportingEnabled();
 bool IsDetectedAgentSignalCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
