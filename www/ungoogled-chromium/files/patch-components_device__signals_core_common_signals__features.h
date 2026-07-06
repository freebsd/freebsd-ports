--- components/device_signals/core/common/signals_features.h.orig	2026-06-05 13:45:06 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -42,7 +42,7 @@ bool IsCertificateCollectionEnabled();
 bool IsContentBindingVersioningEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
