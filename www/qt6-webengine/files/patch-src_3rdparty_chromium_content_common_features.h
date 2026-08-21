--- src/3rdparty/chromium/content/common/features.h.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/content/common/features.h
@@ -63,7 +63,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnUnexpectedO
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnOriginHeaderMismatch);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDumpOnUnexpectedOriginHeader);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
