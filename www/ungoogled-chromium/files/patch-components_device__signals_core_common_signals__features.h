--- components/device_signals/core/common/signals_features.h.orig	2025-05-31 17:16:41 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -29,7 +29,7 @@ bool IsProfileSignalsReportingEnabled();
 bool IsBrowserSignalsReportingEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
