--- components/device_signals/core/common/signals_features.cc.orig	2025-05-07 06:48:23 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -31,7 +31,7 @@ bool IsBrowserSignalsReportingEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
