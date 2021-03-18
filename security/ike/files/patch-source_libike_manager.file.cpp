--- source/libike/manager.file.cpp.orig	2011-02-06 16:40:00 UTC
+++ source/libike/manager.file.cpp
@@ -679,11 +679,11 @@ bool _CONFIG_MANAGER::file_pcf_load( CONFIG & config, 
 			BDATA pwd;
 			data.get( pwd );
 
-			EVP_CIPHER_CTX ctx_cipher;
-			EVP_CIPHER_CTX_init( &ctx_cipher );
+			EVP_CIPHER_CTX *ctx_cipher;
+			ctx_cipher = EVP_CIPHER_CTX_new();
 
 			EVP_CipherInit_ex(
-				&ctx_cipher,
+				ctx_cipher,
 				EVP_des_ede3_cbc(),
 				NULL,
 				key,
@@ -691,7 +691,7 @@ bool _CONFIG_MANAGER::file_pcf_load( CONFIG & config, 
 				0 );
 
 			EVP_Cipher(
-				&ctx_cipher,
+				ctx_cipher,
 				pwd.buff(),
 				pwd.buff(),
 				( unsigned int ) pwd.size() );
