--- chrome/browser/flag_descriptions.h.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8551,6 +8551,18 @@ inline constexpr char kAntivirusTelemetryForDownloadsD
     "Enables antivirus product info to be included in Safe Browsing download "
     "pings.";
 
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
