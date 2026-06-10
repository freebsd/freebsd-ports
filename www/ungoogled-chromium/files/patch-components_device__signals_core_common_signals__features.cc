--- components/device_signals/core/common/signals_features.cc.orig	2026-06-05 13:45:06 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -69,7 +69,7 @@ bool IsContentBindingVersioningEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
