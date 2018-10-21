Obtained from:	https://github.com/LocutusOfBorg/ettercap/commit/f0d63b27c82df2ad5f7ada6310727d841b43fbcc
		https://github.com/LocutusOfBorg/ettercap/commit/def7a62c542241367428223dc460906b0634dcd1

--- src/ec_sslwrap.c.orig	2015-03-14 13:43:11 UTC
+++ src/ec_sslwrap.c
@@ -53,6 +53,10 @@
 #define OPENSSL_NO_KRB5 1
 #include <openssl/ssl.h>
 
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#define HAVE_OPAQUE_RSA_DSA_DH 1 /* since 1.1.0 -pre5 */
+#endif
+
 #define BREAK_ON_ERROR(x,y,z) do {  \
    if (x == -E_INVALID) {            \
       SAFE_FREE(z.DATA.disp_data);  \
@@ -974,9 +978,19 @@ static X509 *sslw_create_selfsigned(X509
    index = X509_get_ext_by_NID(server_cert, NID_authority_key_identifier, -1);
    if (index >=0) {
       ext = X509_get_ext(server_cert, index);
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+      ASN1_OCTET_STRING* os;
+      os = X509_EXTENSION_get_data (ext);
+#endif
       if (ext) {
+#ifdef HAVE_OPAQUE_RSA_DSA_DH
+         os->data[7] = 0xe7;
+         os->data[8] = 0x7e;
+         X509_EXTENSION_set_data (ext, os);
+#else
          ext->value->data[7] = 0xe7;
          ext->value->data[8] = 0x7e;
+#endif
          X509_add_ext(out_cert, ext, -1);
       }
    }
