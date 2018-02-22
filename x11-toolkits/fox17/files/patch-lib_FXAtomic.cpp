--- lib/FXAtomic.cpp.orig	2017-11-29 04:44:13 UTC
+++ lib/FXAtomic.cpp
@@ -54,7 +54,7 @@
 
 
 // New __atomic_XXX() builtins are available
-#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)))
+#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7))) || (defined(__clang__) && defined(__x86_64__))
 #define HAVE_BUILTIN_ATOMIC 1
 #endif
 
@@ -64,7 +64,7 @@
 #endif
 
 // Can we use inline-assembly
-#if (defined(__GNUC__) || defined(__INTEL_COMPILER))
+#if (defined(__GNUC__) || defined(__INTEL_COMPILER)) || defined(__clang__)
 #define HAVE_INLINE_ASSEMBLY 1
 #endif
 
