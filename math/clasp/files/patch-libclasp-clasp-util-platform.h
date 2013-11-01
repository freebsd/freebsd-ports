--- libclasp/clasp/util/platform.h.orig	1970-09-03 18:56:56.000000000 +0100
+++ libclasp/clasp/util/platform.h	1970-09-03 19:04:47.000000000 +0100
@@ -107,7 +107,7 @@
 template <bool> struct static_assertion;
 template <>     struct static_assertion<true> {};
 
-#if !defined(__cplusplus) || __cplusplus < 201103L
+#if !defined(__cplusplus) || !defined(static_assert)
 #define static_assert(x, message) (void)sizeof(static_assertion< (x) >)
 #endif
 
