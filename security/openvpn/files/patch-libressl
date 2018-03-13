--- ./src/openvpn/openssl_compat.h	2018-03-01 07:22:19.000000000 +0000
+++ ./src/openvpn/openssl_compat.h	2018-03-12 10:44:08.876010487 +0000
@@ -711,7 +711,7 @@
 }
 #endif /* SSL_CTX_get_max_proto_version */
 
-#ifndef SSL_CTX_set_min_proto_version
+#if !defined(SSL_CTX_set_min_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_min_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_min_proto_version(SSL_CTX *ctx, long tls_ver_min)
@@ -740,7 +740,7 @@
 }
 #endif /* SSL_CTX_set_min_proto_version */
 
-#ifndef SSL_CTX_set_max_proto_version
+#if !defined(SSL_CTX_set_max_proto_version) && !defined(LIBRESSL_VERSION_NUMBER)
 /** Mimics SSL_CTX_set_max_proto_version for OpenSSL < 1.1 */
 static inline int
 SSL_CTX_set_max_proto_version(SSL_CTX *ctx, long tls_ver_max)
