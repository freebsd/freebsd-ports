
$FreeBSD$

--- include/radiusclient.h.orig	Thu Jan  7 01:53:04 1999
+++ include/radiusclient.h	Wed Jan  8 16:12:50 2003
@@ -169,6 +169,40 @@
 #define PW_ACCT_MULTI_SESSION_ID	50	/* string */
 #define PW_ACCT_LINK_COUNT		51	/* integer */
 
+/*	Experimental SIP-specific attributes */
+
+#define PW_SIP_METHOD			101	/* integer */
+#define PW_SIP_RESPONSE_CODE		102	/* integer */
+#define PW_SIP_CSEQ			103	/* string */
+#define PW_SIP_TO_TAG			104	/* string */
+#define PW_SIP_FROM_TAG			105	/* string */
+#define PW_SIP_BRANCH_ID		106	/* string */
+#define PW_SIP_TRANSLATED_REQUEST_URI	107	/* string */
+#define PW_SIP_SOURCE_IP_ADDRESS	108	/* ipaddr */
+#define PW_SIP_SOURCE_PORT		109	/* integer */
+#define PW_SIP_USER_ID			110	/* string */
+#define PW_SIP_USER_REALM		111	/* string */
+#define PW_SIP_USER_NONCE		112	/* string */
+#define PW_SIP_USER_METHOD		113	/* string */
+#define PW_SIP_USER_DIGEST_URI		114	/* string */
+#define PW_SIP_USER_NONCE_COUNT		115	/* string */
+#define PW_SIP_USER_QOP			116	/* string */
+#define PW_SIP_USER_OPAQUE		117	/* string */
+#define PW_SIP_USER_RESPONSE		118	/* string */
+
+#define PW_DIGEST_RESPONSE		206	/* string */
+#define PW_DIGEST_ATTRIBUTES		207	/* string */
+#define PW_DIGEST_REALM			1063	/* string */
+#define PW_DIGEST_NONCE			1064	/* string */
+#define PW_DIGEST_METHOD		1065	/* string */
+#define PW_DIGEST_URI			1066	/* string */
+#define PW_DIGEST_QOP			1067	/* string */
+#define PW_DIGEST_ALGORITHM		1068	/* string */
+#define PW_DIGEST_BODY_DIGEST		1069	/* string */
+#define PW_DIGEST_CNONCE		1070	/* string */
+#define PW_DIGEST_NONCE_COUNT		1071	/* string */
+#define PW_DIGEST_USER_NAME		1072	/* string */
+
 /*	Merit Experimental Extensions */
 
 #define PW_USER_ID                      222     /* string */
