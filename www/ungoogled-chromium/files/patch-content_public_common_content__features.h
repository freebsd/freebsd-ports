--- content/public/common/content_features.h.orig	2023-01-13 08:56:02 UTC
+++ content/public/common/content_features.h
@@ -272,7 +272,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kVideoPlaybackQual
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kV8VmFuture);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyBaseline);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtection);
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kWebAssemblyCodeProtectionPku);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
         // defined(ARCH_CPU_X86_64)
