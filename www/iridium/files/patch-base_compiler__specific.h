--- base/compiler_specific.h.orig	2024-11-04 08:56:03 UTC
+++ base/compiler_specific.h
@@ -257,7 +257,7 @@
 //
 // In some cases it's desirable to remove this, e.g. on hot functions, or if
 // we have purposely changed the reference canary.
-#if defined(COMPILER_GCC) || defined(__clang__)
+#if (defined(COMPILER_GCC) || defined(__clang__)) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #if HAS_ATTRIBUTE(__no_stack_protector__)
 #define NO_STACK_PROTECTOR __attribute__((__no_stack_protector__))
 #else
@@ -388,7 +388,7 @@ inline constexpr bool AnalyzerAssumeTrue(bool arg) {
 // See https://clang.llvm.org/docs/AttributeReference.html#preserve-most for
 // more details.
 #if (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
-    !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64)) &&       \
+    !((BUILDFLAG(IS_WIN) || BUILDFLAG(IS_OPENBSD)) && defined(ARCH_CPU_ARM64)) &&       \
     !defined(COMPONENT_BUILD) && defined(__clang__) &&       \
     __clang_major__ >= 17 && HAS_ATTRIBUTE(preserve_most)
 #define PRESERVE_MOST __attribute__((preserve_most))
