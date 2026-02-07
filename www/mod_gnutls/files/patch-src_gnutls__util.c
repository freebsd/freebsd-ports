--- src/gnutls_util.c.orig	2021-07-11 11:33:26 UTC
+++ src/gnutls_util.c
@@ -121,7 +121,8 @@ apr_status_t datum_from_file(apr_pool_t *p, const char
 
     /* safe integer type conversion: unsigned int and apr_size_t might
      * have different sizes */
-#if defined(__GNUC__) && __GNUC__ < 5 && !defined(__clang__)
+#if defined(__GNUC__) && __GNUC__ < 5 && \
+    !(defined(__clang__) && __has_builtin(__builtin_add_overflow))
     if (__builtin_expect(br > UINT_MAX, 0))
         return APR_EINVAL;
     else
