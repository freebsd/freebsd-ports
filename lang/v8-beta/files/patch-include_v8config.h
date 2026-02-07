--- include/v8config.h.orig	2022-03-17 10:34:15 UTC
+++ include/v8config.h
@@ -344,7 +344,18 @@ path. Add it with -I<path> to the command line
 # define V8_HAS_CPP_ATTRIBUTE_NO_UNIQUE_ADDRESS \
     (V8_HAS_CPP_ATTRIBUTE(no_unique_address))
 
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
