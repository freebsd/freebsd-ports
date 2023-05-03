--- src/check_nrpe.c.orig	2022-07-18 19:27:53 UTC
+++ src/check_nrpe.c
@@ -899,7 +899,7 @@ void setup_ssl()
 			exit(timeout_return_code);
 		}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 
 	SSL_CTX_set_max_proto_version(ctx, 0);
 
