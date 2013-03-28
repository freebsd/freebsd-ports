--- src/core/CLucene/util/MD5Digester.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/MD5Digester.cpp	2013-03-27 17:16:18.000000000 -0400
@@ -82,7 +82,7 @@
 	for (nCount = 0; nCount < 16; nCount++)
 	{
 		cl_sprintf(chEach, 10, "%02x", md5Digest[nCount]);
-		strncat(chBuffer, chEach, sizeof(chEach));
+		strncat(chBuffer, chEach, 2);
 	}
 
 	return STRDUP_AtoA(chBuffer);
