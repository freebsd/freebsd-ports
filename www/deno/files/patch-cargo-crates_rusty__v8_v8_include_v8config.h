--- cargo-crates/rusty_v8-0.17.0/v8/include/v8config.h.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/rusty_v8-0.17.0/v8/include/v8config.h
@@ -273,7 +273,18 @@
 # define V8_HAS_ATTRIBUTE_WARN_UNUSED_RESULT \
     (__has_attribute(warn_unused_result))
 
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
 # define V8_HAS_BUILTIN_BSWAP16 (__has_builtin(__builtin_bswap16))
 # define V8_HAS_BUILTIN_BSWAP32 (__has_builtin(__builtin_bswap32))
 # define V8_HAS_BUILTIN_BSWAP64 (__has_builtin(__builtin_bswap64))
