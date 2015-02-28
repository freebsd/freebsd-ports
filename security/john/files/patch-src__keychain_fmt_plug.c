--- src/keychain_fmt_plug.c.orig	2012-09-17 10:30:39.000000000 +0200
+++ src/keychain_fmt_plug.c	2015-02-28 20:31:01.902977498 +0100
@@ -119,9 +119,9 @@
 	memcpy(key1, key, 8);
 	memcpy(key2, key + 8, 8);
 	memcpy(key3, key + 16, 8);
-	DES_set_key((C_Block *) key1, &ks1);
-	DES_set_key((C_Block *) key2, &ks2);
-	DES_set_key((C_Block *) key3, &ks3);
+	DES_set_key((DES_cblock *) key1, &ks1);
+	DES_set_key((DES_cblock *) key2, &ks2);
+	DES_set_key((DES_cblock *) key3, &ks3);
 	memcpy(ivec, iv, 8);
 	DES_ede3_cbc_encrypt(data, out, CTLEN, &ks1, &ks2, &ks3, &ivec,  DES_DECRYPT);
 
