--- include/pkixip_ext_asn.h.orig	2014-08-20 04:16:53.000000000 +0900
+++ include/pkixip_ext_asn.h	2014-08-20 04:17:09.000000000 +0900
@@ -33,6 +33,10 @@
 #ifndef	_PKIXIP_EXT_ASN_H
 #define	_PKIXIP_EXT_ASN_H
 
+#include <openssl/stack.h>
+#ifndef STACK
+#define	STACK	_STACK
+#endif
 #include <openssl/asn1t.h>
 #include <openssl/err.h>
 #include <openssl/x509v3.h>
