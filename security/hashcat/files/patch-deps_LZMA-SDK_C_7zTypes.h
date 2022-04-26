--- deps/LZMA-SDK/C/7zTypes.h.orig	2021-11-21 15:39:01 UTC
+++ deps/LZMA-SDK/C/7zTypes.h
@@ -196,8 +196,8 @@ typedef void *LPVOID;
 // typedef void VOID;
 // typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
 // gcc / clang on Unix  : sizeof(long==sizeof(void*) in 32 or 64 bits)
-typedef          long  INT_PTR;
-typedef unsigned long  UINT_PTR;
+// typedef          long  INT_PTR;
+// typedef unsigned long  UINT_PTR;
 typedef          long  LONG_PTR;
 typedef unsigned long  DWORD_PTR;
 
