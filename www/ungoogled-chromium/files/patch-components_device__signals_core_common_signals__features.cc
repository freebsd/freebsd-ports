--- components/device_signals/core/common/signals_features.cc.orig	2025-12-06 13:30:52 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -61,7 +61,7 @@ bool IsSystemSignalCollectionImprovementEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
