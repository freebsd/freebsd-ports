--- cargo-crates/v8-0.97.0/v8/include/v8config.h.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/v8-0.97.0/v8/include/v8config.h
@@ -381,7 +381,18 @@ path. Add it with -I<path> to the command line
 
 # define V8_HAS_BUILTIN_ADD_OVERFLOW (__has_builtin(__builtin_add_overflow))
 # define V8_HAS_BUILTIN_ASSUME (__has_builtin(__builtin_assume))
+// Work around Clang bug present in 9.0.1, at least.
+//
+// Clang stores alignment as a 32-bit unsigned integer, but V8 only uses
+// V8_ASSUME_ALIGNED() for a 4GB (2^32) alignment
+// (kPtrComprIsolateRootAlignment).  As such, the alignment overflows and
+// becomes zero, triggering an internal Clang assertion that alignment must not
+// be zero.
+#if 0
 # define V8_HAS_BUILTIN_ASSUME_ALIGNED (__has_builtin(__builtin_assume_aligned))
+#else
+# define V8_HAS_BUILTIN_ASSUME_ALIGNED 0
+#endif
 # define V8_HAS_BUILTIN_BIT_CAST (__has_builtin(__builtin_bit_cast))
 # define V8_HAS_BUILTIN_BSWAP16 (__has_builtin(__builtin_bswap16))
 # define V8_HAS_BUILTIN_BSWAP32 (__has_builtin(__builtin_bswap32))
