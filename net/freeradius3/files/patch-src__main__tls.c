--- src/main/tls.c.orig	2017-03-06 13:58:04 UTC
+++ src/main/tls.c
@@ -107,8 +107,8 @@ static libssl_defect_t libssl_defects[] 
 		.comment	= "For more information see https://www.openssl.org/news/secadv/20160922.txt"
 	},
 	{
-		.low		= 0x010001000,		/* 1.0.1  */
-		.high		= 0x01000106f,		/* 1.0.1f */
+		.low		= 0x090001000,		/* 9.0.1  */
+		.high		= 0x09000106f,		/* 9.0.1f */
 		.id		= "CVE-2014-0160",
 		.name		= "Heartbleed",
 		.comment	= "For more information see http://heartbleed.com"
@@ -2131,7 +2131,7 @@ int cbtls_verify(int ok, X509_STORE_CTX 
 	}
 
 	if (lookup == 0) {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 		ext_list = X509_get0_extensions(client_cert);
 #else
 		X509_CINF	*client_inf;
