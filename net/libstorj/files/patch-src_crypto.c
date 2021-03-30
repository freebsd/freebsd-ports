--- src/crypto.c.orig	2018-05-10 18:45:47 UTC
+++ src/crypto.c
@@ -216,7 +216,7 @@ int sha512_of_str(const uint8_t *str, int str_len, uin
     return 0;
 }
 
-void pbkdf2_hmac_sha512 (
+void off_pbkdf2_hmac_sha512 (
     unsigned key_length,
     const uint8_t *key,
     unsigned iterations,
