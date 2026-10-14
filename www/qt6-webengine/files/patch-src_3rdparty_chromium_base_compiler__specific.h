--- src/3rdparty/chromium/base/compiler_specific.h.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/base/compiler_specific.h
@@ -198,7 +198,7 @@
 //     MUSTTAIL return Func1(d + 1);  // `Func1()` will be tail-called.
 //   }
 // ```
-#if __has_cpp_attribute(clang::musttail)
+#if __has_cpp_attribute(clang::musttail) && !defined(__powerpc__)
 #define MUSTTAIL [[clang::musttail]]
 #else
 #define MUSTTAIL
@@ -733,6 +733,7 @@ inline constexpr bool AnalyzerAssumeTrue(bool arg) {
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
+    !BUILDFLAG(IS_OPENBSD) &&                                \
     !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else
