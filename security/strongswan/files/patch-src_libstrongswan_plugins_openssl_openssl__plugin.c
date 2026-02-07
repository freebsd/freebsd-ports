--- src/libstrongswan/plugins/openssl/openssl_plugin.c.orig	2024-02-21 15:54:00 UTC
+++ src/libstrongswan/plugins/openssl/openssl_plugin.c
@@ -814,7 +814,7 @@ plugin_t *openssl_plugin_create()
 		},
 	);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	/* note that we can't call OPENSSL_cleanup() when the plugin is destroyed
 	 * as we couldn't initialize the library again afterwards */
 	OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG |
