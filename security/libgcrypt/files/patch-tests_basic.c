--- tests/basic.c.orig	2021-08-22 04:56:06.000000000 -0700
+++ tests/basic.c	2022-12-05 07:46:59.768944000 -0800
@@ -38,6 +38,10 @@
 #else
 #  define ALWAYS_INLINE
 #endif
+#ifdef WITH_DEBUG
+#  undef ALWAYS_INLINE
+#  define ALWAYS_INLINE
+#endif
 
 typedef struct test_spec_pubkey_key
 {
@@ -214,6 +218,7 @@
 }
 
 
+#ifndef WITH_DEBUG
 #if defined(__x86_64__) && defined(HAVE_GCC_INLINE_ASM_SSSE3) && \
     (defined(HAVE_COMPATIBLE_GCC_AMD64_PLATFORM_AS) || \
      defined(HAVE_COMPATIBLE_GCC_WIN64_PLATFORM_AS))
@@ -233,6 +238,7 @@
       defined(__ARM_NEON)
 # define CLUTTER_VECTOR_REGISTER_NEON 1
 # define CLUTTER_VECTOR_REGISTER_COUNT 16
+#endif
 #endif
 
 
