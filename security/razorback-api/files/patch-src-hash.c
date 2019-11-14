--- src/hash.c.orig	2012-01-16 14:17:19.000000000 -0800
+++ src/hash.c	2019-07-03 11:42:06.923894000 -0700
@@ -9,6 +9,19 @@
 
 #include "runtime_config.h"
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+EVP_MD_CTX *EVP_MD_CTX_new(void)
+{
+    return calloc(1, sizeof(EVP_MD_CTX));
+}
+
+void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
+{
+    EVP_MD_CTX_cleanup(ctx);
+    free(ctx);
+}
+#endif
+
 SO_PUBLIC bool
 Hash_IsEqual (const struct Hash *p_pHashA, const struct Hash *p_pHashB)
 {
@@ -96,7 +109,8 @@ Hash_Init_OpenSSL(struct Hash *hash)
         return false;
     }
 
-    EVP_DigestInit(&hash->CTX, m);
+    hash->CTX = EVP_MD_CTX_new();
+    EVP_DigestInit(hash->CTX, m);
 	return true;
 }
 
@@ -129,7 +143,7 @@ Hash_Update (struct Hash * p_pHash, uint8_t * p_pData,
     ASSERT (p_pHash->pData != NULL);
     ASSERT (p_pHash->iType > 0);
     ASSERT (!(p_pHash->iFlags & HASH_FLAG_FINAL));
-    EVP_DigestUpdate(&p_pHash->CTX, p_pData, p_iLength);
+    EVP_DigestUpdate(p_pHash->CTX, p_pData, p_iLength);
     return true;
 }
 SO_PUBLIC bool
@@ -143,7 +157,7 @@ Hash_Update_File (struct Hash * p_pHash, FILE *file)
     ASSERT (!(p_pHash->iFlags & HASH_FLAG_FINAL));
     while((len = fread(data,1,4096, file)) > 0)
     {
-        EVP_DigestUpdate(&p_pHash->CTX, data, len);
+        EVP_DigestUpdate(p_pHash->CTX, data, len);
     }
     rewind(file);
     return true;
@@ -156,7 +170,7 @@ Hash_Finalize (struct Hash * p_pHash)
     ASSERT (p_pHash->pData != NULL);
     ASSERT (p_pHash->iType > 0);
     ASSERT (!(p_pHash->iFlags & HASH_FLAG_FINAL));
-    EVP_DigestFinal(&p_pHash->CTX, p_pHash->pData, &p_pHash->iSize);
+    EVP_DigestFinal(p_pHash->CTX, p_pHash->pData, &p_pHash->iSize);
     p_pHash->iFlags = p_pHash->iFlags | HASH_FLAG_FINAL;
     return true;
 }
@@ -186,7 +200,7 @@ Hash_Destroy (struct Hash *p_pHash)
     if (p_pHash->pData != NULL)
         free (p_pHash->pData);
 
-    EVP_MD_CTX_cleanup(&p_pHash->CTX);
+    EVP_MD_CTX_free(p_pHash->CTX);
     free(p_pHash);
 }
 
