--- runtime/nsd_ossl.c.orig	2021-04-08 06:34:23 UTC
+++ runtime/nsd_ossl.c
@@ -1381,7 +1381,7 @@ osslPostHandshakeCheck(nsd_ossl_t *pNsd)
 	if (SSL_get_shared_ciphers(pNsd->ssl,szDbg, sizeof szDbg) != NULL)
 		dbgprintf("osslPostHandshakeCheck: Debug Shared ciphers = %s\n", szDbg);
 
-	#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+	#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 	if(SSL_get_shared_curve(pNsd->ssl, -1) == 0) {
 		LogError(0, RS_RET_NO_ERRCODE, "nsd_ossl:"
 "No shared curve between syslog client and server.");
