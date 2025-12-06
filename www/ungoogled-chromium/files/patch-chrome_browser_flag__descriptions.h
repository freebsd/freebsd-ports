--- chrome/browser/flag_descriptions.h.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8590,6 +8590,18 @@ inline constexpr char kHandleMdmErrorsForDasherAccount
 inline constexpr char kHandleMdmErrorsForDasherAccountsDescription[] =
     "Enables the mdm error handling feature for dasher accounts";
 
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
