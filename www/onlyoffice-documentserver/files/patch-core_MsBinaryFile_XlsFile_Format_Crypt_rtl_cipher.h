--- core/MsBinaryFile/XlsFile/Format/Crypt/rtl/cipher.h.orig	2023-02-13 11:14:50 UTC
+++ core/MsBinaryFile/XlsFile/Format/Crypt/rtl/cipher.h
@@ -33,7 +33,7 @@
 
 #include <stddef.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
