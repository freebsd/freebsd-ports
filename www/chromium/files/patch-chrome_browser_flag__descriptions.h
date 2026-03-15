--- chrome/browser/flag_descriptions.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8306,6 +8306,18 @@ inline constexpr char kEnableOktaSSOName[] =
 inline constexpr char kEnableOktaSSODescription[] =
     "Enables native support for Okta SSO on managed MacOS devices.";
 
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
