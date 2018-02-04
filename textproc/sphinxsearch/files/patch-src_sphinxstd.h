--- src/sphinxstd.h.orig	2018-02-03 10:22:51 UTC
+++ src/sphinxstd.h
@@ -274,7 +274,7 @@ inline int sphBitCount ( DWORD n )
 	// MIT HACKMEM count
 	// works for 32-bit numbers only
 	// fix last line for 64-bit numbers
-	register DWORD tmp;
+	DWORD tmp;
 	tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
 	return ( (tmp + (tmp >> 3) ) & 030707070707) % 63;
 }
