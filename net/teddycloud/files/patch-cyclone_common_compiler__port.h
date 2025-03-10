--- cyclone/common/compiler_port.h.orig	2024-01-17 21:26:40 UTC
+++ cyclone/common/compiler_port.h
@@ -105,8 +105,8 @@ typedef unsigned int uint_t;
    #define PRIuSIZE "u"
    #define PRIXSIZE "X"
    #define PRIuTIME "lu"
-//Linux GCC compiler
-#elif defined(__linux__)
+//Linux/FreeBSD GCC compiler
+#elif defined(__linux__) || defined(__FreeBSD__)
    #define PRIuSIZE "zu"
    #define PRIXSIZE "zX"
    #define PRIuTIME "lu"
