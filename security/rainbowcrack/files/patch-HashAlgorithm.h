--- HashAlgorithm.h.orig	2014-07-31 12:12:45.000000000 -0400
+++ HashAlgorithm.h	2014-07-31 12:21:55.000000000 -0400
@@ -8,7 +8,12 @@
 #define _HASHALGORITHM_H
 
 void HashLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+void HashNTLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+
+void HashMD4(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
 void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+
 void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+void HashRIPEMD160(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
 
 #endif
