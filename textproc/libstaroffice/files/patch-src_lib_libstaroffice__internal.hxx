--- src/lib/libstaroffice_internal.hxx.orig	2017-07-03 08:05:09 UTC
+++ src/lib/libstaroffice_internal.hxx
@@ -113,9 +113,11 @@ struct STOFF_shared_ptr_noop_deleter {
 /** fall through attributes */
 #define STOFF_FALLTHROUGH
 #if defined(__clang__)
-#  if defined(__has_cpp_attribute) && __has_cpp_attribute(clang::fallthrough)
-#    undef STOFF_FALLTHROUGH
-#    define STOFF_FALLTHROUGH [[clang::fallthrough]]
+#  if defined(__has_cpp_attribute)
+#    if __has_cpp_attribute(clang::fallthrough)
+#      undef STOFF_FALLTHROUGH
+#      define STOFF_FALLTHROUGH [[clang::fallthrough]]
+#    endif
 #  endif
 #elif defined(__GNUC__)
 #  if __GNUC__>=7
