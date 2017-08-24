--- src/gnutls_util.c.orig	2016-12-25 18:36:37 UTC
+++ src/gnutls_util.c
@@ -113,7 +113,8 @@ apr_status_t datum_from_file(apr_pool_t *p, const char
 
     /* safe integer type conversion: unsigned int and apr_size_t might
      * have different sizes */
-#if defined(__GNUC__) && __GNUC__ < 5 && !defined(__clang__)
+#if defined(__GNUC__) && __GNUC__ < 5 && \
+    !(defined(__clang__) && __has_builtin(__builtin_add_overflow))
     if (__builtin_expect(br > UINT_MAX, 0))
         return APR_EINVAL;
     else
