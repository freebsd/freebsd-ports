--- src/check_nrpe.c.orig	2017-04-17 14:21:54 UTC
+++ src/check_nrpe.c
@@ -839,7 +839,7 @@ void setup_ssl()
 			exit(STATE_CRITICAL);
 		}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 
 	SSL_CTX_set_max_proto_version(ctx, 0);
 
