--- include/razorback/types.h.orig	2019-07-03 11:01:48.211000000 -0700
+++ include/razorback/types.h	2019-07-03 11:01:57.144863000 -0700
@@ -56,7 +56,7 @@ struct Hash
     uint32_t iType;             ///< The hash Type.
     uint32_t iSize;             ///< size of the data stored, must be the same for all hashes in system
     uint8_t *pData;             ///< actual data of the hash
-    EVP_MD_CTX CTX;         ///< Private hash data.
+    EVP_MD_CTX *CTX;         ///< Private hash data.
     uint32_t iFlags;            ///< Hash Flags.
 };
 
