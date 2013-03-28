--- src/core/CLucene/util/MD5Digester.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/MD5Digester.cpp	2013-03-27 21:18:10.000000000 -0400
@@ -72,18 +72,16 @@
 // PrintMD5: Converts a completed md5 digest into a char* string.
 char* PrintMD5(uint8_t md5Digest[16])
 {
-	char chBuffer[256];
-	char chEach[10];
+	const char toHex[] = "0123456789abcdef";
+	char chBuffer[16 * 2 + 1];
 	int nCount;
 
-	memset(chBuffer,0,256);
-	memset(chEach, 0, 10);
-
 	for (nCount = 0; nCount < 16; nCount++)
 	{
-		cl_sprintf(chEach, 10, "%02x", md5Digest[nCount]);
-		strncat(chBuffer, chEach, sizeof(chEach));
+		chBuffer[nCount * 2] = toHex[(md5Digest[nCount] & 0xf0) >> 4];
+		chBuffer[nCount * 2 + 1] = toHex[md5Digest[nCount] & 0x0f];
 	}
+	chBuffer[nCount * 2] = '\0';
 
 	return STRDUP_AtoA(chBuffer);
 }
