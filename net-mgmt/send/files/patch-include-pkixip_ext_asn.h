--- include/pkixip_ext_asn.h.orig	2010-08-28 17:58:02.000000000 +0900
+++ include/pkixip_ext_asn.h	2014-08-30 01:54:23.000000000 +0900
@@ -33,6 +33,10 @@
 #ifndef	_PKIXIP_EXT_ASN_H
 #define	_PKIXIP_EXT_ASN_H
 
+#include <openssl/stack.h>
+#if OPENSSL_VERSION_NUMBER >= 0x0090900fL
+#define	STACK	_STACK
+#endif
 #include <openssl/asn1t.h>
 #include <openssl/err.h>
 #include <openssl/x509v3.h>
