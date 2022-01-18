--- core/ASCOfficeXlsFile2/source/XlsFormat/Crypt/rtl/cipher.h.orig	2021-09-30 12:13:32 UTC
+++ core/ASCOfficeXlsFile2/source/XlsFormat/Crypt/rtl/cipher.h
@@ -33,7 +33,7 @@
 
 #include <stddef.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
