--- components/device_signals/core/common/signals_features.cc.orig	2025-11-01 06:40:37 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -51,7 +51,7 @@ bool IsDetectedAgentSignalCollectionEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
