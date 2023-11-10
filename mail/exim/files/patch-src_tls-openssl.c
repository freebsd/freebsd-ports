--- src/tls-openssl.c.orig	2023-11-07 21:07:29.239948000 +0100
+++ src/tls-openssl.c	2023-11-07 21:08:03.517118000 +0100
@@ -2605,7 +2605,7 @@
     asking for certificate-status under DANE, so this callback won't run for
     that combination. It still will for non-DANE. */
 
-#ifdef EXIM_HAVE_OPENSSL_OCSP_RESP_GET0_SIGNER
+#if defined(EXIM_HAVE_OPENSSL_OCSP_RESP_GET0_SIGNER) && defined(SUPPORT_DANE)
     X509 * signer;
 
     if (  tls_out.dane_verified
