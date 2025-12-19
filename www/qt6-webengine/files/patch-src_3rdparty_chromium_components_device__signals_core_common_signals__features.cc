--- src/3rdparty/chromium/components/device_signals/core/common/signals_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/device_signals/core/common/signals_features.cc
@@ -11,7 +11,7 @@ BASE_FEATURE(kAllowClientCertificateReportingForUsers,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
