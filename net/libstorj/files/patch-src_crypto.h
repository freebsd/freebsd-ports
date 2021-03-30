--- src/crypto.h.orig	2018-05-10 18:45:47 UTC
+++ src/crypto.h
@@ -40,7 +40,7 @@ int double_ripemd160sha256(uint8_t *data, uint64_t dat
 int double_ripemd160sha256_as_string(uint8_t *data, uint64_t data_size,
                                     char **digest);
 
-void pbkdf2_hmac_sha512(unsigned key_length,
+void off_pbkdf2_hmac_sha512(unsigned key_length,
                         const uint8_t *key,
                         unsigned iterations,
                         unsigned salt_length, const uint8_t *salt,
