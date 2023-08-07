--- src/openssl/pki_x509_cert.c.orig	2023-06-27 08:58:28.486733000 +0200
+++ src/openssl/pki_x509_cert.c	2023-06-27 13:17:52.669080000 +0200
@@ -433,7 +433,10 @@
         case PKI_SCHEME_ECDSA:
             if ( (int) kParams->ec.form > 0 )
             {
-# if OPENSSL_VERSION_NUMBER < 0x1010000fL
+# if OPENSSL_VERSION_NUMBER >= 0x30000000L
+              EC_KEY_set_conv_form(EVP_PKEY_get1_EC_KEY(certPubKeyVal), 
+              (point_conversion_form_t) kParams->ec.form);
+# elif OPENSSL_VERSION_NUMBER < 0x1010000fL
               EC_KEY_set_conv_form(certPubKeyVal->pkey.ec, 
               			   (point_conversion_form_t) kParams->ec.form);
 # else
@@ -443,7 +446,10 @@
             }
           if ( kParams->ec.asn1flags > -1 )
           {
-# if OPENSSL_VERSION_NUMBER < 0x1010000fL
+# if OPENSSL_VERSION_NUMBER >= 0x30000000L
+            EC_KEY_set_asn1_flag(EVP_PKEY_get1_EC_KEY(certPubKeyVal),
+              kParams->ec.asn1flags );
+# elif OPENSSL_VERSION_NUMBER < 0x1010000fL
             EC_KEY_set_asn1_flag(certPubKeyVal->pkey.ec,
               kParams->ec.asn1flags );
 # else
