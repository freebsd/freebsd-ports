--- src/sphinxint.h.orig	2018-02-03 10:17:12 UTC
+++ src/sphinxint.h
@@ -1074,8 +1074,8 @@ inline int FindBit ( DWORD uValue )
 
 inline int sphEncodeVLB8 ( BYTE * buf, uint64_t v )
 {
-	register BYTE b;
-	register int n = 0;
+	BYTE b;
+	int n = 0;
 
 	do
 	{
