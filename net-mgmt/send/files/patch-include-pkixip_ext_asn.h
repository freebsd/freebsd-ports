--- include/pkixip_ext_asn.h.orig	2010-08-28 08:58:02 UTC
+++ include/pkixip_ext_asn.h
@@ -33,7 +33,12 @@
 #ifndef	_PKIXIP_EXT_ASN_H
 #define	_PKIXIP_EXT_ASN_H
 
+#include <openssl/stack.h>
+#if OPENSSL_VERSION_NUMBER >= 0x0090900fL
+#define	STACK	_STACK
+#endif
 #include <openssl/asn1t.h>
+#include <openssl/asn1.h>
 #include <openssl/err.h>
 #include <openssl/x509v3.h>
 
@@ -45,7 +50,7 @@
 #define	IANA_SAFI_BOTH		3
 #define	IANA_SAFI_MPLS		4
 
-/*
+#ifdef LIBRESSL_VERSION_NUMBER
 typedef struct IPAddressRange_st {
 	ASN1_BIT_STRING		*min;
 	ASN1_BIT_STRING		*max;
@@ -79,7 +84,7 @@ typedef struct IPAddressFamily_st {
 	ASN1_OCTET_STRING	*addressFamily;
 	IPAddressChoice		*ipAddressChoice;
 } IPAddressFamily;
-*/
+#endif
 
 #define IP_AOR_PREFIX		0
 #define IP_AOR_RANGE		1

