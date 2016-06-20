--- src/include/trousers_types.h.orig	2016-06-20 15:21:26 UTC
+++ src/include/trousers_types.h
@@ -11,6 +11,14 @@
 #ifndef _TROUSERS_TYPES_H_
 #define _TROUSERS_TYPES_H_
 
+#ifndef STRUCTURE_PACKING_ATTRIBUTE
+#ifdef __GCC
+#define STRUCTURE_PACKING_ATTRIBUTE   __attribute__((packed))
+#else
+#define STRUCTURE_PACKING_ATTRIBUTE   /* */
+#endif
+#endif
+
 #define TCPA_NONCE_SIZE		sizeof(TCPA_NONCE)
 #define TCPA_DIGEST_SIZE	sizeof(TCPA_DIGEST)
 #define TCPA_ENCAUTH_SIZE	sizeof(TCPA_ENCAUTH)
@@ -100,7 +108,7 @@ typedef struct tdTSS_KEY11_HDR {
 typedef struct tdTSS_KEY12_HDR {
 	TPM_STRUCTURE_TAG tag;
 	UINT16 fill;
-} __attribute__((packed)) TSS_KEY12_HDR;
+} STRUCTURE_PACKING_ATTRIBUTE TSS_KEY12_HDR;
 
 typedef struct tdTSS_KEY {
 	union {
@@ -118,11 +126,10 @@ typedef struct tdTSS_KEY {
 	BYTE *encData;
 } TSS_KEY;
 
-#if (defined (__linux) || defined (linux) || defined (SOLARIS) || defined (__GLIBC__))
-#define BSD_CONST
-#elif (defined (__OpenBSD__) || defined (__FreeBSD__))
+#if defined (__FreeBSD__)
 #define BSD_CONST const
-#endif
-
+#else
+#define BSD_CONST /* */
+#endif 
 
 #endif
