--- src/lib/libwps_internal.h.orig	2017-07-03 07:52:38 UTC
+++ src/lib/libwps_internal.h
@@ -86,9 +86,11 @@ struct WPS_shared_ptr_noop_deleter
 /** fall through attributes */
 #define WPS_FALLTHROUGH
 #if defined(__clang__)
-#  if defined(__has_cpp_attribute) && __has_cpp_attribute(clang::fallthrough)
-#    undef WPS_FALLTHROUGH
-#    define WPS_FALLTHROUGH [[clang::fallthrough]]
+#  if defined(__has_cpp_attribute)
+#    if __has_cpp_attribute(clang::fallthrough)
+#      undef WPS_FALLTHROUGH
+#      define WPS_FALLTHROUGH [[clang::fallthrough]]
+#    endif
 #  endif
 #elif defined(__GNUC__)
 #  if __GNUC__>=7
