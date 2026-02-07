--- components/device_signals/core/common/signals_features.h.orig	2026-01-16 13:40:34 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -40,7 +40,7 @@ bool IsSystemSignalCollectionImprovementEnabled();
 bool IsPolicyDataCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
