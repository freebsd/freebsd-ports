--- content/public/common/content_features.h.orig	2021-07-29 12:15:43 UTC
+++ content/public/common/content_features.h
@@ -219,9 +219,9 @@ CONTENT_EXPORT extern const base::Feature
 CONTENT_EXPORT extern const base::Feature kWebAppWindowControlsOverlay;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyBaseline;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtection;
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT extern const base::Feature kWebAssemblyCodeProtectionPku;
-#endif  // defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 CONTENT_EXPORT extern const base::Feature kWebAssemblyLazyCompilation;
 CONTENT_EXPORT extern const base::Feature kWebAssemblySimd;
 CONTENT_EXPORT extern const base::Feature kWebAssemblyTiering;
