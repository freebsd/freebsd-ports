--- include/scep.h.orig	2002-02-20 00:40:05.000000000 +0100
+++ include/scep.h	2014-07-10 22:24:29.366255595 +0200
@@ -80,7 +80,11 @@
 	int		recipientNonceLength;
 
 	/* OpenSSL configuration file contents				*/
+#ifdef LHASH_OF
+	LHASH_OF(CONF_VALUE) *conf;
+#else
 	LHASH		*conf;
+#endif
 
 	/* signer/client information different from requestor for v2	*/
 	X509		*selfsignedcert;
