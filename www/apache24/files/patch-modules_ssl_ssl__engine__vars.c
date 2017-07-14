--- modules/ssl/ssl_engine_vars.c.orig	2017-03-20 12:01:16 UTC
+++ modules/ssl/ssl_engine_vars.c
@@ -529,7 +529,7 @@ static char *ssl_var_lookup_ssl_cert(apr
         resdup = FALSE;
     }
     else if (strcEQ(var, "A_SIG")) {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         nid = OBJ_obj2nid((ASN1_OBJECT *)(xs->cert_info->signature->algorithm));
 #else
         const ASN1_OBJECT *paobj;
