Index: src/core/ngx_crypt.c
===================================================================
--- src/core/ngx_crypt.c	(revision 3925)
+++ src/core/ngx_crypt.c	(working copy)
@@ -12,6 +12,8 @@
 #endif
 
 
+#if (NGX_CRYPT)
+
 static ngx_int_t ngx_crypt_apr1(ngx_pool_t *pool, u_char *key, u_char *salt,
     u_char **encrypted);
 static ngx_int_t ngx_crypt_plain(ngx_pool_t *pool, u_char *key, u_char *salt,
@@ -232,3 +234,5 @@
 }
 
 #endif /* NGX_HAVE_SHA1 */
+
+#endif /* NGX_CRYPT */
