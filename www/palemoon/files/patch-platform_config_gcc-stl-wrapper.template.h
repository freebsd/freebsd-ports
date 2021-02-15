--- platform/config/gcc-stl-wrapper.template.h.orig	2021-02-05 18:43:01 UTC
+++ platform/config/gcc-stl-wrapper.template.h
@@ -32,6 +32,14 @@
 #  define moz_dont_include_mozalloc_for_cstdlib
 #endif
 
+#ifndef moz_dont_include_mozalloc_for_type_traits
+#  define moz_dont_include_mozalloc_for_type_traits
+#endif
+
+#ifndef moz_dont_include_mozalloc_for_limits
+#  define moz_dont_include_mozalloc_for_limits
+#endif
+
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
