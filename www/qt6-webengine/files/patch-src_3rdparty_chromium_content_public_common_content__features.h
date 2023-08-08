--- src/3rdparty/chromium/content/public/common/content_features.h.orig	2023-07-07 17:40:32 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.h
@@ -275,7 +275,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodePr
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAppWindowControlsOverlay);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyBaseline);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtection);
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtectionPku);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
         // defined(ARCH_CPU_X86_64)
