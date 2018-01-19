------------------------------------------------------------------------
r1806743 | scantor | 2017-08-31 01:23:01 +0200 (Thu, 31 Aug 2017) | 1 line

Fix NULL warnings

Index: xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp
===================================================================
--- xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp	(revision 1806742)
+++ xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp	(revision 1806743)
@@ -151,7 +151,7 @@
                              SymmetricKeyMode mode = MODE_CBC,
                              const unsigned char * iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL);
+                             unsigned int taglen = 0);
 
     /**
      * \brief Continue an decrypt operation using this key.
Index: xsec/enc/XSECCryptoSymmetricKey.hpp
===================================================================
--- xsec/enc/XSECCryptoSymmetricKey.hpp	(revision 1806742)
+++ xsec/enc/XSECCryptoSymmetricKey.hpp	(revision 1806743)
@@ -185,7 +185,7 @@
 							 SymmetricKeyMode mode = MODE_CBC,
 							 const unsigned char* iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL) = 0;
+                             unsigned int taglen = 0) = 0;
 
 	/**
 	 * \brief Continue a decrypt operation using this key.

------------------------------------------------------------------------
