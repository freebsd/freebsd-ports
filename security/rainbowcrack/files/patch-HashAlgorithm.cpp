--- HashAlgorithm.cpp.orig	2014-07-31 12:12:45.000000000 -0400
+++ HashAlgorithm.cpp	2014-07-31 12:21:30.000000000 -0400
@@ -6,9 +6,13 @@
 
 #include "HashAlgorithm.h"
 
+#include "Public.h"
+
 #include <openssl/des.h>
+#include <openssl/md4.h>
 #include <openssl/md5.h>
 #include <openssl/sha.h>
+#include <openssl/ripemd.h>
 #ifdef _WIN32
 	#pragma comment(lib, "libeay32.lib")
 #endif
@@ -48,6 +52,25 @@
 	des_ecb_encrypt((des_cblock*)magic, (des_cblock*)pHash, ks, DES_ENCRYPT);
 }
 
+
+void HashNTLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
+{
+	unsigned char UnicodePlain[MAX_PLAIN_LEN * 2];
+	int i;
+	for (i = 0; i < nPlainLen; i++)
+	{
+		UnicodePlain[i * 2] = pPlain[i];
+		UnicodePlain[i * 2 + 1] = 0x00;
+	}
+
+	MD4(UnicodePlain, nPlainLen * 2, pHash);
+}
+
+void HashMD4(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
+{
+	MD4(pPlain, nPlainLen, pHash);
+}
+
 void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
 {
 	MD5(pPlain, nPlainLen, pHash);
@@ -57,3 +80,9 @@
 {
 	SHA1(pPlain, nPlainLen, pHash);
 }
+
+void HashRIPEMD160(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
+{
+	RIPEMD160(pPlain, nPlainLen, pHash);
+}
+
