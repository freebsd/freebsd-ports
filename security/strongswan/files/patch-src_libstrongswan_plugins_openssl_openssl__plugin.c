--- src/libstrongswan/plugins/openssl/openssl_plugin.c.orig	2025-11-07 19:05:36 UTC
+++ src/libstrongswan/plugins/openssl/openssl_plugin.c
@@ -808,7 +808,7 @@ PLUGIN_DEFINE(openssl)
 		},
 	);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	/* note that we can't call OPENSSL_cleanup() when the plugin is destroyed
 	 * as we couldn't initialize the library again afterwards */
 	OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG |
