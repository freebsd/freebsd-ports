--- third_party/libc++abi/src/include/__cxxabi_config.h.orig	2026-08-12 15:23:09 UTC
+++ third_party/libc++abi/src/include/__cxxabi_config.h
@@ -81,7 +81,7 @@
 #define _LIBCXXABI_DTOR_FUNC
 #endif

-#if __has_include(<ptrauth.h>)
+#if __has_include(<ptrauth.h>) && __has_feature(ptrauth_calls)
 #  include <ptrauth.h>
 #endif

