--- src/sslutils.c.orig	2016-04-19 09:15:43 UTC
+++ src/sslutils.c
@@ -504,7 +504,7 @@ static int ssl_verify_OCSP(int ok, X509_
          * may yield NULL. Return early, but leave the ctx error as is. */
         return OCSP_STATUS_UNKNOWN;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     else if (cert->valid && X509_check_issued(cert,cert) == X509_V_OK) {
 #else
     /* No need to check cert->valid, because ssl_verify_OCSP() only
