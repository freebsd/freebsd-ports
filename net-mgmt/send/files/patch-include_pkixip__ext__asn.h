
$FreeBSD$

--- include/pkixip_ext_asn.h.orig
+++ include/pkixip_ext_asn.h
@@ -45,6 +45,7 @@
 #define	IANA_SAFI_BOTH		3
 #define	IANA_SAFI_MPLS		4
 
+/*
 typedef struct IPAddressRange_st {
 	ASN1_BIT_STRING		*min;
 	ASN1_BIT_STRING		*max;
@@ -52,9 +53,6 @@
 
 typedef struct IPAddressOrRange_st {
 
-#define	IP_AOR_PREFIX		0
-#define	IP_AOR_RANGE		1
-
 	int 			type;
 	union {
 		ASN1_BIT_STRING	*addressPrefix;
@@ -64,8 +62,6 @@
 
 typedef struct IPAddressChoice_st {
 
-#define	IPA_CHOICE_INHERIT	0
-#define	IPA_CHOICE_AOR		1
 
 	int 			type;
 	union {
@@ -78,6 +74,12 @@
 	ASN1_OCTET_STRING	*addressFamily;
 	IPAddressChoice		*ipAddressChoice;
 } IPAddressFamily;
+*/
+
+#define	IP_AOR_PREFIX		0
+#define	IP_AOR_RANGE		1
+#define	IPA_CHOICE_INHERIT	0
+#define	IPA_CHOICE_AOR		1
 
 typedef STACK_OF(IPAddressFamily) IPAddrBlocks;
 
