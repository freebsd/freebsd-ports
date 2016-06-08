--- usr/lib/pkcs11/tpm_stdll/tpm_specific.c.orig	2010-07-29 14:28:41.000000000 +0200
+++ usr/lib/pkcs11/tpm_stdll/tpm_specific.c	2015-02-25 21:42:33.469839036 +0100
@@ -2031,9 +2031,9 @@
 {
 	CK_ULONG       rc;
 
-	des_key_schedule des_key2;
-	const_des_cblock key_val_SSL, in_key_data;
-	des_cblock out_key_data;
+	DES_key_schedule des_key2;
+	const_DES_cblock key_val_SSL, in_key_data;
+	DES_cblock out_key_data;
 	unsigned int i,j;
 
 	// Create the key schedule
@@ -2051,7 +2051,7 @@
 	if (encrypt) {
 		for (i=0; i<in_data_len; i=i+8) {
 			memcpy(in_key_data, in_data+i, 8);
-			des_ecb_encrypt(&in_key_data, &out_key_data, des_key2, DES_ENCRYPT);
+			DES_ecb_encrypt(&in_key_data, &out_key_data, &des_key2, DES_ENCRYPT);
 			memcpy(out_data+i, out_key_data, 8);
 		}
 
@@ -2061,7 +2061,7 @@
 
 		for(j=0; j < in_data_len; j=j+8) {
 			memcpy(in_key_data, in_data+j, 8);
-			des_ecb_encrypt(&in_key_data, &out_key_data, des_key2, DES_DECRYPT);
+			DES_ecb_encrypt(&in_key_data, &out_key_data, &des_key2, DES_DECRYPT);
 			memcpy(out_data+j, out_key_data, 8);
 		}
 
@@ -2083,9 +2083,9 @@
 {
 	CK_ULONG         rc;
 
-	des_cblock ivec;
+	DES_cblock ivec;
 
-	des_key_schedule des_key2;
+	DES_key_schedule des_key2;
 	const_DES_cblock key_val_SSL;
 
 	// Create the key schedule
@@ -2102,11 +2102,11 @@
 
 
 	if ( encrypt){
-		des_ncbc_encrypt(in_data, out_data, in_data_len, des_key2, &ivec, DES_ENCRYPT);
+		DES_ncbc_encrypt(in_data, out_data, in_data_len, &des_key2, &ivec, DES_ENCRYPT);
 		*out_data_len = in_data_len;
 		rc = CKR_OK;
 	} else {
-		des_ncbc_encrypt(in_data, out_data, in_data_len, des_key2, &ivec, DES_DECRYPT);
+		DES_ncbc_encrypt(in_data, out_data, in_data_len, &des_key2, &ivec, DES_DECRYPT);
 		*out_data_len = in_data_len;
 		rc = CKR_OK;
 	}
@@ -2124,12 +2124,12 @@
 	CK_RV  rc;
 
 	unsigned int k, j;
-	des_key_schedule des_key1;
-	des_key_schedule des_key2;
-	des_key_schedule des_key3;
+	DES_key_schedule des_key1;
+	DES_key_schedule des_key2;
+	DES_key_schedule des_key3;
 
-	const_des_cblock key_SSL1, key_SSL2, key_SSL3, in_key_data;
-	des_cblock out_key_data;
+	const_DES_cblock key_SSL1, key_SSL2, key_SSL3, in_key_data;
+	DES_cblock out_key_data;
 
 	// The key as passed is a 24 byte long string containing three des keys
 	// pick them apart and create the 3 corresponding key schedules
@@ -2151,11 +2151,11 @@
 	if (encrypt) {
 		for(k=0;k<in_data_len;k=k+8){
 			memcpy(in_key_data, in_data+k, 8);
-			des_ecb3_encrypt((const_DES_cblock *)&in_key_data,
+			DES_ecb3_encrypt((const_DES_cblock *)&in_key_data,
 					(DES_cblock *)&out_key_data,
-					des_key1,
-					des_key2,
-					des_key3,
+					&des_key1,
+					&des_key2,
+					&des_key3,
 					DES_ENCRYPT);
 			memcpy(out_data+k, out_key_data, 8);
 		}
@@ -2164,11 +2164,11 @@
 	} else {
 		for (j=0;j<in_data_len;j=j+8){
 			memcpy(in_key_data, in_data+j, 8);
-			des_ecb3_encrypt((const_DES_cblock *)&in_key_data,
+			DES_ecb3_encrypt((const_DES_cblock *)&in_key_data,
 					 (DES_cblock *)&out_key_data,
-					des_key1,
-					des_key2,
-					des_key3,
+					&des_key1,
+					&des_key2,
+					&des_key3,
 					DES_DECRYPT);
 			memcpy(out_data+j, out_key_data, 8);
 		}
@@ -2189,12 +2189,12 @@
 {
 
 	CK_RV rc = CKR_OK;
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
 
 	// The key as passed in is a 24 byte string containing 3 keys
 	// pick it apart and create the key schedules
@@ -2216,23 +2216,23 @@
 
 	// Encrypt or decrypt the data
 	if (encrypt){
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
 		rc = CKR_OK;
 	}else {
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
 
