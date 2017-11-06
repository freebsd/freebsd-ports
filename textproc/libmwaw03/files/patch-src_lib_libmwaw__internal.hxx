--- src/lib/libmwaw_internal.hxx.orig	2017-07-03 08:10:43 UTC
+++ src/lib/libmwaw_internal.hxx
@@ -119,9 +119,11 @@ struct MWAW_shared_ptr_noop_deleter {
 /** fall through attributes */
 #define MWAW_FALLTHROUGH
 #if defined(__clang__)
-#  if defined(__has_cpp_attribute) && __has_cpp_attribute(clang::fallthrough)
-#    undef MWAW_FALLTHROUGH
-#    define MWAW_FALLTHROUGH [[clang::fallthrough]]
+#  if defined(__has_cpp_attribute)
+#    if __has_cpp_attribute(clang::fallthrough)
+#      undef MWAW_FALLTHROUGH
+#      define MWAW_FALLTHROUGH [[clang::fallthrough]]
+#    endif
 #  endif
 #elif defined(__GNUC__)
 #  if __GNUC__>=7
