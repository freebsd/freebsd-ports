--- base/compiler_specific.h.orig	2024-12-22 12:24:29 UTC
+++ base/compiler_specific.h
@@ -683,7 +683,7 @@ inline constexpr bool AnalyzerAssumeTrue(bool arg) {
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
-    !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
+    !((BUILDFLAG(IS_WIN) || BUILDFLAG(IS_OPENBSD)) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else
 #define PRESERVE_MOST
