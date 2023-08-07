--- src/openssl/pki_x509_req.c.orig	2023-06-27 08:58:28.487713000 +0200
+++ src/openssl/pki_x509_req.c	2023-06-27 13:17:52.669477000 +0200
@@ -166,7 +166,10 @@
 #ifdef ENABLE_ECDSA
 				case PKI_SCHEME_ECDSA:
     				if ( kParams->ec.form != PKI_EC_KEY_FORM_UNKNOWN ) {
-# if OPENSSL_VERSION_NUMBER > 0x1010000fL
+# if OPENSSL_VERSION_NUMBER >= 0x30000000L
+    					EC_KEY_set_conv_form(EVP_PKEY_get1_EC_KEY(kVal),
+							     (point_conversion_form_t)kParams->ec.form);
+# elif OPENSSL_VERSION_NUMBER > 0x1010000fL
     					EC_KEY_set_conv_form(EVP_PKEY_get0_EC_KEY(kVal),
 							     (point_conversion_form_t)kParams->ec.form);
 # else
