--- core/MsBinaryFile/XlsFile/Format/Crypt/rtl/digest.h.orig	2023-02-13 11:16:13 UTC
+++ core/MsBinaryFile/XlsFile/Format/Crypt/rtl/digest.h
@@ -31,7 +31,7 @@
  */
 #pragma once
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
