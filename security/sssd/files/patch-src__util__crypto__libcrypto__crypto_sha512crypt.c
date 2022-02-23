diff --git src/util/crypto/libcrypto/crypto_sha512crypt.c src/util/crypto/libcrypto/crypto_sha512crypt.c
index 2275ccd96..c1e418917 100644
--- src/util/crypto/libcrypto/crypto_sha512crypt.c
+++ src/util/crypto/libcrypto/crypto_sha512crypt.c
@@ -30,6 +30,13 @@
 
 #include "sss_openssl.h"
 
+#ifndef HAVE_MEMPCPY
+void *
+mempcpy (void *dest, const void *src, size_t n)
+{
+  return (char *) memcpy (dest, src, n) + n;
+}
+#endif /* HAVE_MEMPCPY */
 
 /* Define our magic string to mark salt for SHA512 "encryption" replacement. */
 const char sha512_salt_prefix[] = "$6$";
