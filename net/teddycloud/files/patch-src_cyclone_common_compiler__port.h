--- src/cyclone/common/compiler_port.h.orig	2024-11-04 17:31:41 UTC
+++ src/cyclone/common/compiler_port.h
@@ -106,7 +106,7 @@ typedef unsigned int uint_t;
    #define PRIXSIZE "X"
    #define PRIuTIME "lu"
 //Linux GCC compiler
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__unix__)
    #define PRIuSIZE "zu"
    #define PRIXSIZE "zX"
    #define PRIuTIME "lu"
