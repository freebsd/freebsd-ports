--- plugins/obs-outputs/librtmp/rtmp.h.orig	2020-03-20 10:48:43 UTC
+++ plugins/obs-outputs/librtmp/rtmp.h
@@ -94,7 +94,7 @@ typedef tls_ctx *TLS_CTX;
   mbedtls_ssl_init(s);\
   mbedtls_ssl_setup(s, &ctx->conf);\
 	mbedtls_ssl_config_defaults(&ctx->conf, MBEDTLS_SSL_IS_CLIENT, MBEDTLS_SSL_TRANSPORT_STREAM, MBEDTLS_SSL_PRESET_DEFAULT);\
-  mbedtls_ssl_conf_authmode(&ctx->conf, MBEDTLS_SSL_VERIFY_REQUIRED);\
+  mbedtls_ssl_conf_authmode(&ctx->conf, MBEDTLS_SSL_VERIFY_NONE);\
 	mbedtls_ssl_conf_rng(&ctx->conf, mbedtls_ctr_drbg_random, &ctx->ctr_drbg)
 
 #define TLS_setfd(s,fd)	mbedtls_ssl_set_bio(s, fd, mbedtls_net_send, mbedtls_net_recv, NULL)
