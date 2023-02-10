--- src/openvpn/openssl_compat.h.orig	2020-04-16 13:26:45 UTC
+++ src/openvpn/openssl_compat.h
@@ -747,7 +747,7 @@ SSL_CTX_get_max_proto_version(SSL_CTX *ctx)
 }
 #endif /* SSL_CTX_get_max_proto_version */
 
-#ifndef SSL_CTX_set_min_proto_version
+#if !defined(SSL_CTX_set_min_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_min_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_ver_min)
@@ -776,7 +776,7 @@ SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_v
 }
 #endif /* SSL_CTX_set_min_proto_version */
 
-#ifndef SSL_CTX_set_max_proto_version
+#if !defined(SSL_CTX_set_max_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_max_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_max_proto_version(SSL_CTX *ctx, long tls_ver_max)
