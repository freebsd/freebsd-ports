--- src/libstrongswan/plugins/openssl/openssl_plugin.c.orig	2016-10-08 12:17:09 UTC
+++ src/libstrongswan/plugins/openssl/openssl_plugin.c
@@ -20,6 +20,10 @@
 #include <threading/mutex.h>
 #include <threading/thread_value.h>
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+
 #include <openssl/err.h>
 #include <openssl/evp.h>
 #include <openssl/conf.h>
@@ -623,7 +627,7 @@ plugin_t *openssl_plugin_create()
 		},
 	);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	/* note that we can't call OPENSSL_cleanup() when the plugin is destroyed
 	 * as we couldn't initialize the library again afterwards */
 	OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG |
