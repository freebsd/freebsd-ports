--- base/compiler_specific.h.orig	2025-05-07 06:48:23 UTC
+++ base/compiler_specific.h
@@ -729,6 +729,7 @@ inline constexpr bool AnalyzerAssumeTrue(bool arg) {
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
+    !BUILDFLAG(IS_OPENBSD) &&                                \
     !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else
