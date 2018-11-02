--- common/slp_crypto.c.orig	2012-12-08 00:13:28.000000000 +0400
+++ common/slp_crypto.c	2018-10-29 14:49:49.343271000 +0300
@@ -83,18 +83,7 @@
  */
 SLPCryptoDSAKey * SLPCryptoDSAKeyDup(SLPCryptoDSAKey * dsa)
 {
-   SLPCryptoDSAKey * result;
-
-   result =  DSA_new();
-   if (result)
-   {
-      result->p = BN_dup(dsa->p);
-      result->q = BN_dup(dsa->q);
-      result->g = BN_dup(dsa->g);
-      result->priv_key = BN_dup(dsa->priv_key);
-      result->pub_key = BN_dup(dsa->pub_key);
-   }
-   return result;
+   return DSAparams_dup(dsa);
 }
 
 /** Destroy a key that was created by SLPCryptoDSAKeyCreate.
