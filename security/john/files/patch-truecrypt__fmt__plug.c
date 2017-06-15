--- truecrypt_fmt_plug.c.orig	2014-12-18 07:59:02 UTC
+++ truecrypt_fmt_plug.c
@@ -310,8 +310,8 @@ static int crypt_all(int *pcount, struct
 			pbkdf2_sha512_sse((const unsigned char **)pin, lens, psalt->salt, 64, psalt->num_iterations, &(x.poutc), sizeof(key), 0);
 		}
 #else
-		if (is_sha512)
-			pbkdf2_sha512((const unsigned char*)key_buffer[i], strlen(key_buffer[i]), psalt->salt, 64, num_iterations, key, sizeof(key), 0);
+		if (psalt->hash_type == IS_SHA512)
+			pbkdf2_sha512((const unsigned char*)key_buffer[i], strlen((char*)key_buffer[i]), psalt->salt, 64, psalt->num_iterations, key, sizeof(key), 0);
 #endif
 		else if (psalt->hash_type == IS_RIPEMD160)
 			pbkdf2_ripemd160(key_buffer[i], strlen((char*)(key_buffer[i])), psalt->salt, 64, psalt->num_iterations, key, sizeof(key), 0);
