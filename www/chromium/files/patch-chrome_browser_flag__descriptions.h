--- chrome/browser/flag_descriptions.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8514,6 +8514,18 @@ inline constexpr char kEnableDlpFileSystemApiDescripti
     "Enable DLP upload scan support for FileSystem API-backed cloud storage on "
     "ChromeOS.";
 
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
