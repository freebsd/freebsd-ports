--- src/ibnum.h.orig	2003-01-17 00:49:04 UTC
+++ src/ibnum.h
@@ -60,7 +60,7 @@ int num_array_get(P4(const ref *, int, u
 int sdecode_number(P3(const byte *, int, ref *));
 int sdecodeshort(P2(const byte *, int));
 uint sdecodeushort(P2(const byte *, int));
-long sdecodelong(P2(const byte *, int));
+int sdecodeint32(P2(const byte *, int));
 float sdecodefloat(P2(const byte *, int));
 
 #endif /* ibnum_INCLUDED */
