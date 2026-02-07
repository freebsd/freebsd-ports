--- modules/ssl/ssl_private.h.orig	2018-03-23 14:22:26 UTC
+++ modules/ssl/ssl_private.h
@@ -123,7 +123,7 @@
 #define MODSSL_SSL_METHOD_CONST
 #endif
 
-#if defined(LIBRESSL_VERSION_NUMBER)
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L
 /* Missing from LibreSSL */
 #if LIBRESSL_VERSION_NUMBER < 0x2060000f
 #define SSL_CTRL_SET_MIN_PROTO_VERSION          123
