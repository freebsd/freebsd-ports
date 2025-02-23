--- components/device_signals/core/common/signals_features.h.orig	2025-02-22 18:06:53 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -31,7 +31,7 @@ enum class NewEvFunction { kFileSystemInfo, kSettings,
 bool IsNewFunctionEnabled(NewEvFunction new_ev_function);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
