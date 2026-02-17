--- content/common/features.h.orig	2026-02-15 10:01:45 UTC
+++ content/common/features.h
@@ -67,7 +67,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kCopyFromSurfaceAl
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kCriticalClientHint);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDeviceBoundSessionsDevTools);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
@@ -105,7 +105,7 @@ enum class FontDataServiceTypefaceType {
 CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServiceTypefaceType,
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kFontDataServiceLinux);
 enum class FontDataServiceTypefaceType {
   kFreetype,
@@ -115,7 +115,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServ
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled();
 #endif
 
