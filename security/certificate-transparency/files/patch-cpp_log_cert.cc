--- cpp/log/cert.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/log/cert.cc
@@ -31,7 +31,7 @@ using util::StatusOr;
 using util::error::Code;
 
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(OPENSSL_IS_BORINGSSL)
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(OPENSSL_IS_BORINGSSL) || defined(LIBRESSL_VERSION_NUMBER)
 // Backport from 1.0.2-beta3.
 static int i2d_re_X509_tbs(X509* x, unsigned char** pp) {
   x->cert_info->enc.modified = 1;
@@ -39,7 +39,7 @@ static int i2d_re_X509_tbs(X509* x, unsi
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
 static int X509_get_signature_nid(const X509* x) {
   return OBJ_obj2nid(x->sig_alg->algorithm);
 }
