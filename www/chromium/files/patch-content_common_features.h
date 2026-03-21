--- content/common/features.h.orig	2026-03-13 06:02:14 UTC
+++ content/common/features.h
@@ -72,7 +72,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDisableAutoResize
 CONTENT_EXPORT BASE_DECLARE_FEATURE(
     kDocumentIsolationPolicyWithoutSiteIsolation);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kDocumentPolicyNegotiation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnforceSameDocumentOriginInvariants);
@@ -110,7 +110,7 @@ enum class FontDataServiceTypefaceType {
 CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServiceTypefaceType,
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kFontDataServiceLinux);
 enum class FontDataServiceTypefaceType {
   kFreetype,
@@ -120,7 +120,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE_PARAM(FontDataServ
                                           kFontDataServiceTypefaceType);
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsFontDataServiceEnabled();
 #endif
 
