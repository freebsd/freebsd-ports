--- ./HashAlgorithm.h.orig	2008-07-22 20:30:34.000000000 -0400
+++ ./HashAlgorithm.h	2008-07-22 20:31:07.000000000 -0400
@@ -8,7 +8,13 @@
 #define _HASHALGORITHM_H
 
 void HashLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+void HashNTLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+
+void HashMD2(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+void HashMD4(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
 void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+
 void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
+void HashRIPEMD160(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
 
 #endif
