--- restricted-plugin-ptw/aircrack-crypto.cc.orig	2018-10-10 00:29:38 UTC
+++ restricted-plugin-ptw/aircrack-crypto.cc
@@ -232,7 +232,7 @@ void calc_pmk( char *key, char *essid_pre, uchar pmk[4
 // void calc_ptk (struct WPA_hdsk *wpa, unsigned char bssid[6], unsigned char pmk[32], unsigned char ptk[80]) {
 // 	int i;
 // 	uchar pke[100];
-// 	HMAC_CTX ctx;
+// 	HMAC_CTX *ctx;
 //
 // 	memcpy( pke, "Pairwise key expansion", 23 );
 //
@@ -258,23 +258,23 @@ void calc_pmk( char *key, char *essid_pre, uchar pmk[4
 // 		memcpy( pke + 67, wpa->snonce, 32 );
 // 	}
 //
-// 	HMAC_CTX_init(&ctx);
-// 	HMAC_Init_ex(&ctx, pmk, 32, EVP_sha1(), NULL);
+// 	ctx = HMAC_CTX_new();
+// 	HMAC_Init_ex(ctx, pmk, 32, EVP_sha1(), NULL);
 // 	for(i = 0; i < 4; i++ )
 // 	{
 // 		pke[99] = i;
 // 		//HMAC(EVP_sha1(), values[0], 32, pke, 100, ptk + i * 20, NULL);
-// 		HMAC_Init_ex(&ctx, 0, 0, 0, 0);
-// 		HMAC_Update(&ctx, pke, 100);
-// 		HMAC_Final(&ctx, ptk + i*20, NULL);
+// 		HMAC_Init_ex(ctx, 0, 0, 0, 0);
+// 		HMAC_Update(ctx, pke, 100);
+// 		HMAC_Final(ctx, ptk + i*20, NULL);
 // 	}
-// 	HMAC_CTX_cleanup(&ctx);
+// 	HMAC_CTX_free(ctx);
 // }
 
 void calc_mic (struct AP_info *ap, unsigned char pmk[32], unsigned char ptk[80], unsigned char mic[20]) {
 	int i;
 	uchar pke[100];
-	HMAC_CTX ctx;
+	HMAC_CTX *ctx;
 
 	memcpy( pke, "Pairwise key expansion", 23 );
 
@@ -300,17 +300,17 @@ void calc_mic (struct AP_info *ap, unsigned char pmk[3
 		memcpy( pke + 67, ap->wpa.snonce, 32 );
 	}
 
-	HMAC_CTX_init(&ctx);
-	HMAC_Init_ex(&ctx, pmk, 32, EVP_sha1(), NULL);
+	ctx = HMAC_CTX_new();
+	HMAC_Init_ex(ctx, pmk, 32, EVP_sha1(), NULL);
 	for(i = 0; i < 4; i++ )
 	{
 		pke[99] = i;
 		//HMAC(EVP_sha1(), values[0], 32, pke, 100, ptk + i * 20, NULL);
-		HMAC_Init_ex(&ctx, 0, 0, 0, 0);
-		HMAC_Update(&ctx, pke, 100);
-		HMAC_Final(&ctx, ptk + i*20, NULL);
+		HMAC_Init_ex(ctx, 0, 0, 0, 0);
+		HMAC_Update(ctx, pke, 100);
+		HMAC_Final(ctx, ptk + i*20, NULL);
 	}
-	HMAC_CTX_cleanup(&ctx);
+	HMAC_CTX_free(ctx);
 
 	if( ap->wpa.keyver == 1 )
 	{
