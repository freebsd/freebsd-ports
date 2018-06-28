commit 4ffbb46cf9c63dfddc062771a9bb29a5d50524af
Author: Dmitry Marakasov <amdmi3@amdmi3.ru>
Date:   Wed Jun 27 22:31:01 2018 +0300

    Fix "macro expansion producing 'defined' has undefined behavior" clang warning

diff --git libi2pd/Crypto.h libi2pd/Crypto.h
index fe0fcddf..43f1def9 100644
--- libi2pd/Crypto.h
+++ libi2pd/Crypto.h
@@ -262,7 +262,12 @@ namespace crypto
 
 // take care about openssl version
 #include <openssl/opensslv.h>
-#define LEGACY_OPENSSL ((OPENSSL_VERSION_NUMBER < 0x010100000) || defined(LIBRESSL_VERSION_NUMBER)) // 1.0.2 and below or LibreSSL
+#if ((OPENSSL_VERSION_NUMBER < 0x010100000) || defined(LIBRESSL_VERSION_NUMBER)) // 1.0.2 and below or LibreSSL
+#   define LEGACY_OPENSSL 1
+#else
+#   define LEGACY_OPENSSL 0
+#endif
+
 #if LEGACY_OPENSSL
 // define getters and setters introduced in 1.1.0
 inline int DSA_set0_pqg(DSA *d, BIGNUM *p, BIGNUM *q, BIGNUM *g)
