--- runtime/net_ossl.c.orig	2025-03-05 18:14:51 UTC
+++ runtime/net_ossl.c
@@ -514,6 +514,7 @@ void net_ossl_lastOpenSSLErrorMsg
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 /* initialize tls config commands in openssl context
  */
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 rsRetVal net_ossl_apply_tlscgfcmd(net_ossl_t *pThis, uchar *tlscfgcmd)
 {
 	DEFiRet;
@@ -630,6 +631,7 @@ finalize_it:
 	}
 	RETiRet;
 }
+#endif
 
 
 
