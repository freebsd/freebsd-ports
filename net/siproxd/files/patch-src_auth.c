--- src/auth.c.orig	2008-01-19 17:07:14.000000000 +0100
+++ src/auth.c	2008-03-31 10:58:24.000000000 +0200
@@ -367,25 +367,25 @@
 		   OUT HASHHEX SessionKey
 		   )
 {
-  MD5_CTX Md5Ctx;
+  osip_MD5_CTX Md5Ctx;
   HASH HA1;
   
-  MD5Init(&Md5Ctx);
-  if (pszUserName) MD5Update(&Md5Ctx, pszUserName, strlen(pszUserName));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszRealm)    MD5Update(&Md5Ctx, pszRealm, strlen(pszRealm));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszPassword) MD5Update(&Md5Ctx, pszPassword, strlen(pszPassword));
-  MD5Final(HA1, &Md5Ctx);
+  osip_MD5Init(&Md5Ctx);
+  if (pszUserName) osip_MD5Update(&Md5Ctx, pszUserName, strlen(pszUserName));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszRealm)    osip_MD5Update(&Md5Ctx, pszRealm, strlen(pszRealm));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszPassword) osip_MD5Update(&Md5Ctx, pszPassword, strlen(pszPassword));
+  osip_MD5Final(HA1, &Md5Ctx);
 
   if ((pszAlg!=NULL) && (osip_strcasecmp(pszAlg, "md5-sess") == 0)) {
-    MD5Init(&Md5Ctx);
-    MD5Update(&Md5Ctx, HA1, HASHLEN);
-    MD5Update(&Md5Ctx, ":", 1);
-    if (pszNonce)  MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
-    MD5Update(&Md5Ctx, ":", 1);
-    if (pszCNonce) MD5Update(&Md5Ctx, pszCNonce, strlen(pszCNonce));
-    MD5Final(HA1, &Md5Ctx);
+    osip_MD5Init(&Md5Ctx);
+    osip_MD5Update(&Md5Ctx, HA1, HASHLEN);
+    osip_MD5Update(&Md5Ctx, ":", 1);
+    if (pszNonce)  osip_MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
+    osip_MD5Update(&Md5Ctx, ":", 1);
+    if (pszCNonce) osip_MD5Update(&Md5Ctx, pszCNonce, strlen(pszCNonce));
+    osip_MD5Final(HA1, &Md5Ctx);
   };
   CvtHex(HA1, SessionKey);
 }
@@ -403,57 +403,57 @@
 			OUT HASHHEX Response    /* request-digest or response-digest */
 			)
 {
-  MD5_CTX Md5Ctx;
+  osip_MD5_CTX Md5Ctx;
   HASH HA2;
   HASH RespHash;
   HASHHEX HA2Hex;
   
   /* calculate H(A2) */
-  MD5Init(&Md5Ctx);
-  if (pszMethod)   MD5Update(&Md5Ctx, pszMethod, strlen(pszMethod));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszDigestUri)MD5Update(&Md5Ctx, pszDigestUri, strlen(pszDigestUri));
+  osip_MD5Init(&Md5Ctx);
+  if (pszMethod)   osip_MD5Update(&Md5Ctx, pszMethod, strlen(pszMethod));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszDigestUri)osip_MD5Update(&Md5Ctx, pszDigestUri, strlen(pszDigestUri));
   
   if (pszQop!=NULL) {
       goto auth_withqop;
   };
   
   /* auth_withoutqop: */
-  MD5Final(HA2, &Md5Ctx);
+  osip_MD5Final(HA2, &Md5Ctx);
   CvtHex(HA2, HA2Hex);
 
   /* calculate response */
-  MD5Init(&Md5Ctx);
-  MD5Update(&Md5Ctx, HA1, HASHHEXLEN);
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszNonce)    MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
-  MD5Update(&Md5Ctx, ":", 1);
+  osip_MD5Init(&Md5Ctx);
+  osip_MD5Update(&Md5Ctx, HA1, HASHHEXLEN);
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszNonce)    osip_MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
+  osip_MD5Update(&Md5Ctx, ":", 1);
 
   goto end;
 
  auth_withqop:
 
-  MD5Update(&Md5Ctx, ":", 1);
-  MD5Update(&Md5Ctx, HEntity, HASHHEXLEN);
-  MD5Final(HA2, &Md5Ctx);
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  osip_MD5Update(&Md5Ctx, HEntity, HASHHEXLEN);
+  osip_MD5Final(HA2, &Md5Ctx);
   CvtHex(HA2, HA2Hex);
 
   /* calculate response */
-  MD5Init(&Md5Ctx);
-  MD5Update(&Md5Ctx, HA1, HASHHEXLEN);
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszNonce)    MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszNonceCount)MD5Update(&Md5Ctx, pszNonceCount, strlen(pszNonceCount));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszCNonce)   MD5Update(&Md5Ctx, pszCNonce, strlen(pszCNonce));
-  MD5Update(&Md5Ctx, ":", 1);
-  if (pszQop)      MD5Update(&Md5Ctx, pszQop, strlen(pszQop));
-  MD5Update(&Md5Ctx, ":", 1);
+  osip_MD5Init(&Md5Ctx);
+  osip_MD5Update(&Md5Ctx, HA1, HASHHEXLEN);
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszNonce)    osip_MD5Update(&Md5Ctx, pszNonce, strlen(pszNonce));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszNonceCount)osip_MD5Update(&Md5Ctx, pszNonceCount, strlen(pszNonceCount));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszCNonce)   osip_MD5Update(&Md5Ctx, pszCNonce, strlen(pszCNonce));
+  osip_MD5Update(&Md5Ctx, ":", 1);
+  if (pszQop)      osip_MD5Update(&Md5Ctx, pszQop, strlen(pszQop));
+  osip_MD5Update(&Md5Ctx, ":", 1);
 
  end:
-  MD5Update(&Md5Ctx, HA2Hex, HASHHEXLEN);
-  MD5Final(RespHash, &Md5Ctx);
+  osip_MD5Update(&Md5Ctx, HA2Hex, HASHHEXLEN);
+  osip_MD5Final(RespHash, &Md5Ctx);
   CvtHex(RespHash, Response);
 }
 
