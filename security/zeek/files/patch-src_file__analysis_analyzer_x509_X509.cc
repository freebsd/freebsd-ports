--- src/file_analysis/analyzer/x509/X509.cc.orig	2026-05-12 18:14:44 UTC
+++ src/file_analysis/analyzer/x509/X509.cc
@@ -349,7 +349,8 @@ void X509::ParseSAN(X509_EXTENSION* ext) {
             }
 
             auto len = ASN1_STRING_length(gen->d.ia5);
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
             const char* name = (const char*)ASN1_STRING_data(gen->d.ia5);
 #else
             const char* name = (const char*)ASN1_STRING_get0_data(gen->d.ia5);
