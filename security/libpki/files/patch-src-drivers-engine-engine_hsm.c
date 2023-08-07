--- src/drivers/engine/engine_hsm.c.orig	2023-06-27 08:58:28.477634000 +0200
+++ src/drivers/engine/engine_hsm.c	2023-06-27 13:17:52.663862000 +0200
@@ -204,7 +204,9 @@
 	char *engine_id = NULL;
 
 	ENGINE_load_builtin_engines();
+#if OPENSSL_VERSION_NUMBER < 0x30000000
 	ERR_load_ENGINE_strings();
+#endif
 
 	hsm = (HSM *) PKI_Malloc ( sizeof( HSM ));
 	memcpy( hsm, &engine_hsm, sizeof( HSM ));
