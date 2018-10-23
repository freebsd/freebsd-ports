--- dh.h.orig	2016-02-29 01:15:13 UTC
+++ dh.h
@@ -253,20 +253,23 @@ DHInit(int nKeyBits)
   if (!dh)
     goto failed;
 
-  MP_new(dh->g);
+  const BIGNUM *p;
+  const BIGNUM *g;
+  DH_get0_pqg(dh,&p,NULL,&g);
+  MP_new(g);
 
-  if (!dh->g)
+  if (!g)
     goto failed;
 
-  MP_gethex(dh->p, P1024, res);	/* prime P1024, see dhgroups.h */
+  MP_gethex(p, P1024, res);	/* prime P1024, see dhgroups.h */
   if (!res)
     {
       goto failed;
     }
 
-  MP_set_w(dh->g, 2);	/* base 2 */
+  MP_set_w(g, 2);	/* base 2 */
 
-  dh->length = nKeyBits;
+  DH_set_length(dh, nKeyBits);
   return dh;
 
 failed:
@@ -293,12 +296,15 @@ DHGenerateKey(MDH *dh)
       MP_gethex(q1, Q1024, res);
       assert(res);
 
-      res = isValidPublicKey(dh->pub_key, dh->p, q1);
+      BIGNUM *pub_key, *priv_key, *p;
+      DH_get0_key(dh, &pub_key, &priv_key);
+      DH_get0_pqg(dh,&p,NULL,NULL);
+      res = isValidPublicKey(pub_key, p, q1);
       if (!res)
 	{
-	  MP_free(dh->pub_key);
-	  MP_free(dh->priv_key);
-	  dh->pub_key = dh->priv_key = 0;
+	  MP_free(pub_key);
+	  MP_free(priv_key);
+          DH_set0_key(dh, 0, 0);
 	}
 
       MP_free(q1);
@@ -314,15 +320,17 @@ static int
 DHGetPublicKey(MDH *dh, uint8_t *pubkey, size_t nPubkeyLen)
 {
   int len;
-  if (!dh || !dh->pub_key)
+  BIGNUM *pub_key;
+  DH_get0_key(dh, &pub_key, NULL);
+  if (!dh || !pub_key)
     return 0;
 
-  len = MP_bytes(dh->pub_key);
+  len = MP_bytes(pub_key);
   if (len <= 0 || len > (int) nPubkeyLen)
     return 0;
 
   memset(pubkey, 0, nPubkeyLen);
-  MP_setbin(dh->pub_key, pubkey + (nPubkeyLen - len), len);
+  MP_setbin(pub_key, pubkey + (nPubkeyLen - len), len);
   return 1;
 }
 
@@ -364,7 +372,9 @@ DHComputeSharedSecretKey(MDH *dh, uint8_t *pubkey, siz
   MP_gethex(q1, Q1024, len);
   assert(len);
 
-  if (isValidPublicKey(pubkeyBn, dh->p, q1))
+  BIGNUM *p;
+  DH_get0_pqg(dh,&p,NULL,NULL);
+  if (isValidPublicKey(pubkeyBn, p, q1))
     res = MDH_compute_key(secret, nPubkeyLen, pubkeyBn, dh);
   else
     res = -1;
