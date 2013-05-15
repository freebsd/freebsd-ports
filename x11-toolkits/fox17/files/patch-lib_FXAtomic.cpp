--- lib/FXAtomic.cpp.orig	2013-05-15 09:08:20.000000000 +0200
+++ lib/FXAtomic.cpp	2013-05-15 09:09:22.000000000 +0200
@@ -71,11 +71,17 @@
 #if defined( __INTEL_COMPILER ) && !defined( __ia64__ )
 #undef HAVE_BUILTIN_SYNC
 #endif
+#if defined(__FreeBSD__) && defined(__amd64__) && __FreeBSD_version < 900000
+#undef HAVE_BUILTIN_SYNC
+#endif
 #endif
 
 // Have inline assembly only when using GNU C++ or Intel C++
 #if (defined(__GNUC__) || defined(__INTEL_COMPILER))
 #define HAVE_INLINE_ASSEMBLY 1
+#if defined(__FreeBSD__) && defined(__amd64__) && __FreeBSD_version < 900000
+#undef HAVE_INLINE_ASSEMBLY
+#endif
 #endif
 
 
