--- runtime/net_ossl.c.orig	2024-02-26 08:24:02 UTC
+++ runtime/net_ossl.c
@@ -460,6 +460,7 @@ void net_ossl_lastOpenSSLErrorMsg
 
 /* initialize tls config commands in openssl context
  */
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 rsRetVal net_ossl_apply_tlscgfcmd(net_ossl_t *pThis, uchar *tlscfgcmd)
 {
 	DEFiRet;
@@ -543,6 +544,7 @@ finalize_it:
 finalize_it:
 	RETiRet;
 }
+#endif
 
 
 /* Convert a fingerprint to printable data. The  conversion is carried out
