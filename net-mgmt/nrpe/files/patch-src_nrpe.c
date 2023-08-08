--- src/nrpe.c.orig	2022-07-18 19:27:53 UTC
+++ src/nrpe.c
@@ -357,7 +357,7 @@ void init_ssl(void)
 		exit(STATE_CRITICAL);
 	}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 
 	SSL_CTX_set_max_proto_version(ctx, 0);
 
