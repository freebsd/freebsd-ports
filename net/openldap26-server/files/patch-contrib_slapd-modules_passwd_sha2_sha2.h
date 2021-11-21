--- contrib/slapd-modules/passwd/sha2/sha2.h.orig	2021-07-27 17:44:47 UTC
+++ contrib/slapd-modules/passwd/sha2/sha2.h
@@ -142,6 +142,21 @@ typedef struct _SHA512_CTX {
 
 typedef SHA512_CTX SHA384_CTX;
 
+#define	SHA256_Init	_sha2_SHA256_Init
+#define	SHA256_Update	_sha2_SHA256_Update
+#define	SHA256_Final	_sha2_SHA256_Final
+#define	SHA256_End	_sha2_SHA256_End
+#define	SHA256_Data	_sha2_SHA256_Data
+#define	SHA384_Init	_sha2_SHA384_Init
+#define	SHA384_Update	_sha2_SHA384_Update
+#define	SHA384_Final	_sha2_SHA384_Final
+#define	SHA384_End	_sha2_SHA384_End
+#define	SHA384_Data	_sha2_SHA384_Data
+#define	SHA512_Init	_sha2_SHA512_Init
+#define	SHA512_Update	_sha2_SHA512_Update
+#define	SHA512_Final	_sha2_SHA512_Final
+#define	SHA512_End	_sha2_SHA512_End
+#define	SHA512_Data	_sha2_SHA512_Data
 
 /*** SHA-256/384/512 Function Prototypes ******************************/
 /* avoid symbol clash with other crypto libs */
