--- components/device_signals/core/common/signals_features.h.orig	2025-12-05 10:12:50 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -37,7 +37,7 @@ bool IsDetectedAgentSignalCollectionEnabled();
 bool IsSystemSignalCollectionImprovementEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
