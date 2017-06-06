--- libyara/modules/pe.c.orig	2017-06-05 16:57:34 UTC
+++ libyara/modules/pe.c
@@ -41,7 +41,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #include <openssl/bio.h>
 #include <openssl/pkcs7.h>
 #include <openssl/x509.h>
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define X509_get_signature_nid(o) OBJ_obj2nid((o)->sig_alg->algorithm)
 #endif
 #endif
