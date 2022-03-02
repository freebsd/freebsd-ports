--- content/public/common/content_features.h.orig	2022-02-28 16:54:41 UTC
+++ content/public/common/content_features.h
@@ -249,7 +249,7 @@ CONTENT_EXPORT extern const base::Feature
 CONTENT_EXPORT extern const base::Feature kWebAppWindowControlsOverlay;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyBaseline;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtection;
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtectionPku;
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
         // defined(ARCH_CPU_X86_64)
