--- content/public/common/content_features.h.orig	2022-12-06 08:09:13 UTC
+++ content/public/common/content_features.h
@@ -272,7 +272,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kV8VmFuture);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAppWindowControlsOverlay);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyBaseline);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtection);
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtectionPku);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
         // defined(ARCH_CPU_X86_64)
