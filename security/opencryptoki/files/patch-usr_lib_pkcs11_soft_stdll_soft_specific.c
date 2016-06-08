--- usr/lib/pkcs11/soft_stdll/soft_specific.c.orig	2010-07-29 14:28:41.000000000 +0200
+++ usr/lib/pkcs11/soft_stdll/soft_specific.c	2015-02-25 21:39:34.150913516 +0100
@@ -426,14 +426,14 @@
 {
 	CK_ULONG       rc;
 	
-	des_key_schedule des_key2;
-   	const_des_cblock key_val_SSL, in_key_data;
-	des_cblock out_key_data;
+	DES_key_schedule des_key2;
+   	const_DES_cblock key_val_SSL, in_key_data;
+	DES_cblock out_key_data;
 	unsigned int i,j;
 
   	// Create the key schedule
 	memcpy(&key_val_SSL, key_value, 8);
-	des_set_key_unchecked(&key_val_SSL, des_key2);
+	des_set_key_unchecked(&key_val_SSL, &des_key2);
 
 	// the des decrypt will only fail if the data length is not evenly divisible
 	// by 8
@@ -446,7 +446,7 @@
 	if (encrypt) {
 		for (i=0; i<in_data_len; i=i+8) {
 			memcpy(in_key_data, in_data+i, 8);
-			des_ecb_encrypt(&in_key_data, &out_key_data, des_key2, DES_ENCRYPT);
+			DES_ecb_encrypt(&in_key_data, &out_key_data, &des_key2, DES_ENCRYPT);
 			memcpy(out_data+i, out_key_data, 8);
 		}
 
@@ -456,7 +456,7 @@
  
 		for(j=0; j < in_data_len; j=j+8) {
 			memcpy(in_key_data, in_data+j, 8);
-			des_ecb_encrypt(&in_key_data, &out_key_data, des_key2, DES_DECRYPT);
+			DES_ecb_encrypt(&in_key_data, &out_key_data, &des_key2, DES_DECRYPT);
 			memcpy(out_data+j, out_key_data, 8);
 		}
      
@@ -478,14 +478,14 @@
 {
 	CK_ULONG         rc;
 	
-	des_cblock ivec;
+	DES_cblock ivec;
 
-	des_key_schedule des_key2;
-   	const_des_cblock key_val_SSL;
+	DES_key_schedule des_key2;
+   	const_DES_cblock key_val_SSL;
 
 	// Create the key schedule
 	memcpy(&key_val_SSL, key_value, 8);
-   	des_set_key_unchecked(&key_val_SSL, des_key2);
+   	des_set_key_unchecked(&key_val_SSL, &des_key2);
    
 	memcpy(&ivec, init_v, 8);
 	// the des decrypt will only fail if the data length is not evenly divisible
@@ -497,11 +497,11 @@
 
 
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
@@ -519,12 +519,12 @@
 	CK_RV  rc;
 
 	unsigned int k,j;
-	des_key_schedule des_key1;
-	des_key_schedule des_key2;
-	des_key_schedule des_key3;
+	DES_key_schedule des_key1;
+	DES_key_schedule des_key2;
+	DES_key_schedule des_key3;
 
-   	const_des_cblock key_SSL1, key_SSL2, key_SSL3, in_key_data;
-	des_cblock out_key_data;
+   	const_DES_cblock key_SSL1, key_SSL2, key_SSL3, in_key_data;
+	DES_cblock out_key_data;
 
 	// The key as passed is a 24 byte long string containing three des keys
 	// pick them apart and create the 3 corresponding key schedules
@@ -546,11 +546,11 @@
 	if (encrypt) {
 		for(k=0;k<in_data_len;k=k+8){
 		memcpy(in_key_data, in_data+k, 8);
-		des_ecb3_encrypt((const_DES_cblock *)&in_key_data, 
+		DES_ecb3_encrypt((const_DES_cblock *)&in_key_data, 
 			 (DES_cblock *)&out_key_data, 
-				des_key1, 
-				des_key2,
-				des_key3,
+				&des_key1, 
+				&des_key2,
+				&des_key3,
 				DES_ENCRYPT);
 		memcpy(out_data+k, out_key_data, 8);
 	}
@@ -559,11 +559,11 @@
 	} else {
 		for (j=0;j<in_data_len;j=j+8){
 		memcpy(in_key_data, in_data+j, 8);
-		des_ecb3_encrypt((const_DES_cblock *)&in_key_data,
+		DES_ecb3_encrypt((const_DES_cblock *)&in_key_data,
 			 (DES_cblock *)&out_key_data, 
-				des_key1,
-				des_key2,
-				des_key3, 
+				&des_key1,
+				&des_key2,
+				&des_key3, 
 				DES_DECRYPT);
 		memcpy(out_data+j, out_key_data, 8);
 	}
@@ -584,12 +584,12 @@
 {
 
 	CK_RV rc = CKR_OK;
-	des_key_schedule des_key1;
-	des_key_schedule des_key2;
-	des_key_schedule des_key3;
+	DES_key_schedule des_key1;
+	DES_key_schedule des_key2;
+	DES_key_schedule des_key3;
 
-   	const_des_cblock key_SSL1, key_SSL2, key_SSL3;
-	des_cblock ivec;
+   	const_DES_cblock key_SSL1, key_SSL2, key_SSL3;
+	DES_cblock ivec;
 
 	// The key as passed in is a 24 byte string containing 3 keys
 	// pick it apart and create the key schedules
@@ -611,23 +611,23 @@
 
 	// Encrypt or decrypt the data
 	if (encrypt){
-		des_ede3_cbc_encrypt(in_data,
+		DES_ede3_cbc_encrypt(in_data,
 			     out_data,
 			     in_data_len,
-			     des_key1,
-			     des_key2,
-			     des_key3,
+			     &des_key1,
+			     &des_key2,
+			     &des_key3,
 			     &ivec,
 			     DES_ENCRYPT);
 	*out_data_len = in_data_len;
 	rc = CKR_OK;
 	}else {
-		des_ede3_cbc_encrypt(in_data,
+		DES_ede3_cbc_encrypt(in_data,
 					out_data,
 					in_data_len,
-					des_key1,
-					des_key2,
-					des_key3,
+					&des_key1,
+					&des_key2,
+					&des_key3,
 					&ivec,
 					DES_DECRYPT);
 
