Fix build for FreeBSD 9.x base OpenSSL and LibreSSL.  Fix for LibreSSL is
already in upstream repository, so this file can be removed once FreeBSD 9.x
support is dropped AND the next version of megatools is released.
--- lib/mega.c.orig	2016-11-03 13:45:42 UTC
+++ lib/mega.c
@@ -29,7 +29,9 @@
 #include <string.h>
 #include <time.h>
 #include <openssl/aes.h>
+#if OPENSSL_VERSION_NUMBER >= 0x101000000L && !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/modes.h>
+#endif
 #include <openssl/bn.h>
 #include <openssl/rsa.h>
 #include <openssl/rand.h>
@@ -803,7 +805,7 @@ static gboolean rsa_key_gen(rsa_key* k)
     return FALSE;
   }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x101000000L && !defined(LIBRESSL_VERSION_NUMBER)
   RSA_get0_key(key, &k->m, &k->e, &k->d);
   RSA_get0_factors(key, &k->q, &k->p);
   RSA_get0_crt_params(key, NULL, NULL, &k->u);
@@ -2988,7 +2990,7 @@ struct _put_data
   GByteArray* buffer;
 };
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x101000000L && !defined(LIBRESSL_VERSION_NUMBER)
 void AES_ctr128_encrypt(
   const unsigned char *in, 
   unsigned char *out,
