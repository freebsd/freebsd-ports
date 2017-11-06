--- src/gnutls_io.c.orig	2016-12-25 18:36:37 UTC
+++ src/gnutls_io.c
@@ -23,7 +23,8 @@
 APLOG_USE_MODULE(gnutls);
 #endif
 
-#if defined(__GNUC__) && __GNUC__ < 5 && !defined(__clang__)
+#if defined(__GNUC__) && __GNUC__ < 5 && \
+    !(defined(__clang__) && __has_builtin(__builtin_add_overflow))
 #include <inttypes.h>
 #endif
 
@@ -572,18 +573,21 @@ apr_status_t mgs_filter_input(ap_filter_t * f,
          * might have different lengths. Read sizes should be too
          * small for 32 or 64 bit to matter, but we have to make
          * sure. */
-#if defined(__GNUC__) && __GNUC__ < 5 && !defined(__clang__)
+#if defined(__GNUC__) && __GNUC__ < 5 && \
+    !(defined(__clang__) && __has_builtin(__builtin_add_overflow))
         if ((apr_size_t) readbytes < len)
         {
+#if INTMAX_MAX > SIZE_MAX
             /* If readbytes is negative the function fails in the
              * check above, but the compiler doesn't get that. */
-            if (__builtin_expect(imaxabs(readbytes) > SIZE_MAX, 0))
+            if (__builtin_expect(imaxabs(readbytes) > (intmax_t) SIZE_MAX, 0))
             {
                 ap_log_cerror(APLOG_MARK, APLOG_CRIT, APR_EINVAL, ctxt->c,
                               "%s: prevented buffer length overflow",
                               __func__);
                 return APR_EINVAL;
             }
+#endif
             len = (apr_size_t) readbytes;
         }
 #else
