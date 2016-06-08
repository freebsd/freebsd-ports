--- nasl/nasl_init.c.orig	2005-11-01 18:27:57 UTC
+++ nasl/nasl_init.c
@@ -256,14 +256,18 @@ static init_func libfuncs[] = {
   "MD4", nasl_md4, 1, { NULL },
 #endif
   "MD5", nasl_md5, 1, { NULL }, 
+#ifndef OPENSSL_NO_SHA0
   "SHA", nasl_sha, 1, { NULL },
+#endif
   "SHA1", nasl_sha1, 1, { NULL },
   "RIPEMD160", nasl_ripemd160, 1, { NULL },
 #ifdef HAVE_OPENSSL_MD2_H  
   "HMAC_MD2", nasl_hmac_md2, 0, { "data", "key", NULL },
 #endif  
   "HMAC_MD5", nasl_hmac_md5, 0, { "data", "key", NULL },
+#ifndef OPENSSL_NO_SHA0
   "HMAC_SHA", nasl_hmac_sha, 0, { "data", "key", NULL },
+#endif
   "HMAC_SHA1", nasl_hmac_sha1, 0, { "data", "key", NULL },
   "HMAC_DSS", nasl_hmac_dss, 0, { "data", "key", NULL },
  
