--- src/openvpn/openssl_compat.h.orig	2019-02-20 12:28:23 UTC
+++ src/openvpn/openssl_compat.h
@@ -735,7 +735,7 @@ SSL_CTX_get_max_proto_version(SSL_CTX *ctx)
 }
 #endif /* SSL_CTX_get_max_proto_version */
 
-#ifndef SSL_CTX_set_min_proto_version
+#if !defined(SSL_CTX_set_min_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_min_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_ver_min)
@@ -764,7 +764,7 @@ SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_v
 }
 #endif /* SSL_CTX_set_min_proto_version */
 
-#ifndef SSL_CTX_set_max_proto_version
+#if !defined(SSL_CTX_set_max_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_max_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_max_proto_version(SSL_CTX *ctx, long tls_ver_max)
