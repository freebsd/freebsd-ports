--- CryptoPkg/Library/OpensslLib/openssl/crypto/uid.c.orig	2019-03-20 05:39:21 UTC
+++ CryptoPkg/Library/OpensslLib/openssl/crypto/uid.c
@@ -14,6 +14,8 @@
 
 # include OPENSSL_UNISTD
 
+int issetugid(void);
+
 int OPENSSL_issetugid(void)
 {
     return issetugid();
