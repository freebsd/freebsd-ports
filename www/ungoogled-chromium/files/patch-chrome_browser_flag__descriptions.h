--- chrome/browser/flag_descriptions.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8565,6 +8565,18 @@ inline constexpr char kAndroidEntraSsoDescription[] =
     "Enables native support for Entra SSO on Android provided by selected "
     "Authentication Brokers.";
 
+#if BUILDFLAG(IS_BSD)
+inline constexpr char kAudioBackendName[] =
+    "Audio Backend";
+inline constexpr char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
+
 // ============================================================================
 // Don't just add flags to the end, put them in the alphabetical order.
 // ============================================================================
