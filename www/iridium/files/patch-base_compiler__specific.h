--- base/compiler_specific.h.orig	2024-08-27 06:28:16 UTC
+++ base/compiler_specific.h
@@ -326,7 +326,7 @@
 //
 // In some cases it's desirable to remove this, e.g. on hot functions, or if
 // we have purposely changed the reference canary.
-#if defined(COMPILER_GCC) || defined(__clang__)
+#if (defined(COMPILER_GCC) || defined(__clang__)) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #if HAS_ATTRIBUTE(__no_stack_protector__)
 #define NO_STACK_PROTECTOR __attribute__((__no_stack_protector__))
 #else
