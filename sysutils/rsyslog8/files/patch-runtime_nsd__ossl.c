--- runtime/nsd_ossl.c.orig	2024-02-26 08:24:02 UTC
+++ runtime/nsd_ossl.c
@@ -798,7 +798,7 @@ osslPostHandshakeCheck(nsd_ossl_t *pNsd)
 	if (SSL_get_shared_ciphers(pNsd->pNetOssl->ssl,szDbg, sizeof szDbg) != NULL)
 		dbgprintf("osslPostHandshakeCheck: Debug Shared ciphers = %s\n", szDbg);
 
-	#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 	if(SSL_get_shared_curve(pNsd->pNetOssl->ssl, -1) == 0) {
 		// This is not a failure
 		LogMsg(0, RS_RET_NO_ERRCODE, LOG_INFO, "nsd_ossl: "
