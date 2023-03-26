--- core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h.orig	2023-01-27 21:00:04.000000000 +0100
+++ core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h	2023-02-13 11:18:01.384933000 +0100
@@ -31,7 +31,7 @@
  */
 #pragma once
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
