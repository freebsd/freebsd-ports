This fixes building against LibreSSL.

--- src/lib-ssl-iostream/dovecot-openssl-common.c.orig	2016-12-03 18:13:25 UTC
+++ src/lib-ssl-iostream/dovecot-openssl-common.c
@@ -101,7 +101,7 @@ bool dovecot_openssl_common_global_unref
 	ERR_remove_thread_state(NULL);
 #endif
 	ERR_free_strings();
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	OPENSSL_cleanup();
 #endif
 	return FALSE;
