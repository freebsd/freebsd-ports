--- src/_cffi_src/openssl/x509_vfy.py.orig	2017-01-27 15:09:52 UTC
+++ src/_cffi_src/openssl/x509_vfy.py
@@ -221,10 +221,16 @@ static const long X509_V_ERR_SUITE_B_INV
 static const long X509_V_ERR_SUITE_B_INVALID_SIGNATURE_ALGORITHM = 0;
 static const long X509_V_ERR_SUITE_B_LOS_NOT_ALLOWED = 0;
 static const long X509_V_ERR_SUITE_B_CANNOT_SIGN_P_384_WITH_P_256 = 0;
+#ifndef X509_V_ERR_HOSTNAME_MISMATCH
 static const long X509_V_ERR_HOSTNAME_MISMATCH = 0;
+#endif
+#ifndef X509_V_ERR_EMAIL_MISMATCH
 static const long X509_V_ERR_EMAIL_MISMATCH = 0;
+#endif
+#ifndef X509_V_ERR_IP_ADDRESS_MISMATCH
 static const long X509_V_ERR_IP_ADDRESS_MISMATCH = 0;
 #endif
+#endif
 
 /* OpenSSL 1.0.2beta2+ verification parameters */
 #if CRYPTOGRAPHY_OPENSSL_102BETA2_OR_GREATER && \
