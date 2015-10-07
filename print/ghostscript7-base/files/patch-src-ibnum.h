--- src/ibnum.h.orig	2013-04-30 10:50:12.000000000 +0900
+++ src/ibnum.h	2013-04-30 10:50:29.000000000 +0900
@@ -60,7 +60,7 @@
 int sdecode_number(P3(const byte *, int, ref *));
 int sdecodeshort(P2(const byte *, int));
 uint sdecodeushort(P2(const byte *, int));
-long sdecodelong(P2(const byte *, int));
+int sdecodeint32(P2(const byte *, int));
 float sdecodefloat(P2(const byte *, int));
 
 #endif /* ibnum_INCLUDED */
