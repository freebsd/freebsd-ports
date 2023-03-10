--- pgputil.c.orig	2003-04-30 04:13:38 UTC
+++ pgputil.c
@@ -221,14 +221,14 @@ decode_x509 (ddesc * data, long len, ddesc * keyid)
     {
       return (0);
     }
-  switch (pkey->type)
+  switch (EVP_PKEY_type(EVP_PKEY_id(pkey)))
     {
     case EVP_PKEY_RSA:
       /* pkey->pkey.rsa->n is the modulus */
-      b = BN_dup (pkey->pkey.rsa->n);
+      b = BN_dup (RSA_get0_n(EVP_PKEY_get0_RSA(pkey)));
       break;
     case EVP_PKEY_DSA:
-      b = BN_dup (pkey->pkey.dsa->p);
+      b = BN_dup (DSA_get0_p(EVP_PKEY_get0_DSA(pkey)));
       break;
     }
   EVP_PKEY_free (pkey);
