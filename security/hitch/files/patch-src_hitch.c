--- src/hitch.c.orig	2016-12-22 13:48:49 UTC
+++ src/hitch.c
@@ -683,7 +683,7 @@ load_privatekey(SSL_CTX *ctx, const char
 		return NULL;
 	}
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define SSL_CTX_get_default_passwd_cb(ctx) (ctx->default_passwd_callback)
 #define SSL_CTX_get_default_passwd_cb_userdata(ctx) (ctx->default_passwd_callback_userdata)
 #endif
