--- src/racoon/crypto_openssl.c.orig	2006-12-18 16:18:10.000000000 +0600
+++ src/racoon/crypto_openssl.c	2008-03-28 16:36:05.000000000 +0600
@@ -1391,15 +1391,15 @@
 	RC5_32_KEY ks;
 
 	/* in RFC 2451, there is information about the number of round. */
-	RC5_32_set_key(&ks, key->l, key->v, 16);
+	RC5_32_set_key(&ks, key->l, (unsigned char*)key->v, 16);
 
 	/* allocate buffer for result */
 	if ((res = vmalloc(data->l)) == NULL)
 		return NULL;
 
 	/* decryption data */
-	RC5_32_cbc_encrypt(data->v, res->v, data->l,
-		&ks, iv->v, RC5_ENCRYPT);
+	RC5_32_cbc_encrypt( (unsigned char*)data->v, (unsigned char*)res->v, data->l,
+		&ks, (unsigned char*)iv->v, RC5_ENCRYPT);
 
 	return res;
 }
@@ -1412,15 +1412,15 @@
 	RC5_32_KEY ks;
 
 	/* in RFC 2451, there is information about the number of round. */
-	RC5_32_set_key(&ks, key->l, key->v, 16);
+	RC5_32_set_key(&ks, key->l, (unsigned char*)key->v, 16);
 
 	/* allocate buffer for result */
 	if ((res = vmalloc(data->l)) == NULL)
 		return NULL;
 
 	/* decryption data */
-	RC5_32_cbc_encrypt(data->v, res->v, data->l,
-		&ks, iv->v, RC5_DECRYPT);
+	RC5_32_cbc_encrypt( (unsigned char*)data->v, (unsigned char*)res->v, data->l,
+		&ks, (unsigned char*)iv->v, RC5_DECRYPT);
 
 	return res;
 }
