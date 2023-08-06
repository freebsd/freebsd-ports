--- oscam.c.orig	2023-08-06 18:22:04 UTC
+++ oscam.c
@@ -49,7 +49,9 @@
 static void ssl_init(void)
 {
 	SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
 	ERR_load_BIO_strings();
+#endif
 	ERR_load_SSL_strings();
 	SSL_library_init();
 }
@@ -1807,7 +1809,7 @@ int32_t main(int32_t argc, char *argv[])
 #ifdef CS_CACHEEX_AIO
 	init_cw_cache();
 	init_ecm_cache();
-#endif	
+#endif
 	cs_init_log();
 	init_machine_info();
 	init_check();
@@ -1899,7 +1901,7 @@ int32_t main(int32_t argc, char *argv[])
 	led_status_starting();
 
 	ac_init();
-	
+
 	gbox_send_init_hello();
 
 	start_thread("card poll", (void *) &card_poll, NULL, NULL, 1, 1);
