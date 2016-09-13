--- usr/lib/pkcs11/common/sw_crypt.c.orig	2016-04-29 17:26:46 UTC
+++ usr/lib/pkcs11/common/sw_crypt.c
@@ -309,12 +309,12 @@ sw_des3_cbc(CK_BYTE * in_data,
 	    CK_BYTE  *key_value,
 	    CK_BYTE  encrypt)
 {
-	des_key_schedule des_key1;
-	des_key_schedule des_key2;
-	des_key_schedule des_key3;
+	DES_key_schedule des_key1;
+	DES_key_schedule des_key2;
+	DES_key_schedule des_key3;
 
-	const_des_cblock key_SSL1, key_SSL2, key_SSL3;
-	des_cblock ivec;
+	const_DES_cblock key_SSL1, key_SSL2, key_SSL3;
+	DES_cblock ivec;
 
 	// the des decrypt will only fail if the data length is not evenly divisible
 	// by 8
@@ -328,30 +328,30 @@ sw_des3_cbc(CK_BYTE * in_data,
 	memcpy(&key_SSL1, key_value, (size_t)8);
 	memcpy(&key_SSL2, key_value+8, (size_t)8);
 	memcpy(&key_SSL3, key_value+16, (size_t)8);
-	des_set_key_unchecked(&key_SSL1, des_key1);
-	des_set_key_unchecked(&key_SSL2, des_key2);
-	des_set_key_unchecked(&key_SSL3, des_key3);
+	DES_set_key_unchecked(&key_SSL1, &des_key1);
+	DES_set_key_unchecked(&key_SSL2, &des_key2);
+	DES_set_key_unchecked(&key_SSL3, &des_key3);
 
 	memcpy(ivec, init_v, sizeof(ivec));
 
 	// Encrypt or decrypt the data
 	if (encrypt) {
-		des_ede3_cbc_encrypt(in_data,
+		DES_ede3_cbc_encrypt(in_data,
 				out_data,
 				in_data_len,
-				des_key1,
-				des_key2,
-				des_key3,
+				&des_key1,
+				&des_key2,
+				&des_key3,
 				&ivec,
 				DES_ENCRYPT);
 		*out_data_len = in_data_len;
 	} else {
-		des_ede3_cbc_encrypt(in_data,
+		DES_ede3_cbc_encrypt(in_data,
 				out_data,
 				in_data_len,
-				des_key1,
-				des_key2,
-				des_key3,
+				&des_key1,
+				&des_key2,
+				&des_key3,
 				&ivec,
 				DES_DECRYPT);
 
