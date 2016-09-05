--- ncat/test/test-wildcard.c.orig	2016-08-01 09:34:56 UTC
+++ ncat/test/test-wildcard.c
@@ -253,7 +253,7 @@ static int set_dNSNames(X509 *cert, cons
         if (gen_name == NULL)
             goto stack_err;
         gen_name->type = GEN_DNS;
-    #if OPENSSL_VERSION_NUMBER < 0x10100000L
+    #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         gen_name->d.dNSName = M_ASN1_IA5STRING_new();
     #else
         gen_name->d.dNSName = ASN1_IA5STRING_new();
