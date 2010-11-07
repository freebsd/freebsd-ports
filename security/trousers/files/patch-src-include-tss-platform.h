--- src/include/tss/platform.h.orig	2010-01-29 01:27:51.000000000 +0900
+++ src/include/tss/platform.h	2010-10-24 21:04:04.830556101 +0900
@@ -15,7 +15,7 @@
 #if !defined(WIN32)
 #include <stdint.h>
    typedef uint8_t            BYTE;
-   typedef int8_t             TSS_BOOL;
+   typedef uint8_t            TSS_BOOL;
    typedef uint16_t           UINT16;
    typedef uint32_t           UINT32;
    typedef uint64_t           UINT64;
