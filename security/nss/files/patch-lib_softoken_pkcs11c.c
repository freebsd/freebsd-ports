--- lib/softoken/pkcs11c.c.orig	2010-05-05 14:36:05.000000000 +0000
+++ lib/softoken/pkcs11c.c	2010-05-05 14:37:25.000000000 +0000
@@ -5679,9 +5679,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
             break;
         case NSSLOWKEYDSAKey:
             keyType = CKK_DSA;
-            crv = (sftk_hasAttribute(key, CKA_NETSCAPE_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
@@ -5722,9 +5719,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
 #ifndef NSS_DISABLE_ECC
         case NSSLOWKEYECKey:
             keyType = CKK_EC;
-            crv = (sftk_hasAttribute(key, CKA_NETSCAPE_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
