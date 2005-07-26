--- modules/ssl/ssl_engine_kernel.c	2005/06/08 09:00:24	189561
+++ modules/ssl/ssl_engine_kernel.c	2005/06/08 09:08:09	189562
@@ -1398,7 +1398,7 @@
             BIO_printf(bio, ", nextUpdate: ");
             ASN1_UTCTIME_print(bio, X509_CRL_get_nextUpdate(crl));
 
-            n = BIO_read(bio, buff, sizeof(buff));
+            n = BIO_read(bio, buff, sizeof(buff) - 1);
             buff[n] = '\0';
 
             BIO_free(bio);
