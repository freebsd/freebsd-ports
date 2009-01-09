--- crypto/evp/enc_min.c.orig	2008-12-02 19:14:44.000000000 +0100
+++ crypto/evp/enc_min.c	2009-01-09 18:20:35.000000000 +0100
@@ -199,7 +199,7 @@
 			enc = 1;
 		ctx->encrypt = enc;
 		}
-#ifdef OPENSSL_NO_FIPS
+#ifndef OPENSSL_NO_FIPS
 	if(FIPS_selftest_failed())
 		{
 		FIPSerr(FIPS_F_EVP_CIPHERINIT_EX,FIPS_R_FIPS_SELFTEST_FAILED);
