--- ncat/ncat_ssl.c.orig	2016-08-01 09:34:56 UTC
+++ ncat/ncat_ssl.c
@@ -315,7 +315,7 @@ static int cert_match_dnsname(X509 *cert
 
     /* We must copy this address into a temporary variable because ASN1_item_d2i
        increments it. We don't want it to corrupt ext->value->data. */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     data = ext->value->data;
 #else
     ASN1_OCTET_STRING* asn1_str = X509_EXTENSION_get_data(ext);
@@ -328,7 +328,7 @@ static int cert_match_dnsname(X509 *cert
        presence of null bytes. */
 #if (OPENSSL_VERSION_NUMBER > 0x00907000L)
     if (method->it != NULL) {
-    #if OPENSSL_VERSION_NUMBER < 0x10100000L
+    #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         gen_names = (STACK_OF(GENERAL_NAME) *) ASN1_item_d2i(NULL,
             (const unsigned char **) &data,
             ext->value->length, ASN1_ITEM_ptr(method->it));
@@ -339,7 +339,7 @@ static int cert_match_dnsname(X509 *cert
             asn1_str_a->length, ASN1_ITEM_ptr(method->it));
     #endif
     } else {
-    #if OPENSSL_VERSION_NUMBER < 0x10100000L
+    #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         gen_names = (STACK_OF(GENERAL_NAME) *) method->d2i(NULL,
             (const unsigned char **) &data,
             ext->value->length);
