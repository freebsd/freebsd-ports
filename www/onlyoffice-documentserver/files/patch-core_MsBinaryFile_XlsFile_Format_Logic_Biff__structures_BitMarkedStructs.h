--- core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h.orig	2025-08-02 18:33:34 UTC
+++ core/MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BitMarkedStructs.h
@@ -31,7 +31,7 @@
  */
 #pragma once
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #include <inttypes.h>
 #endif
 
