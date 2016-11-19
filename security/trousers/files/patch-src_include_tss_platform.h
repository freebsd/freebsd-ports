--- src/include/tss/platform.h.orig	2016-11-19 03:09:49 UTC
+++ src/include/tss/platform.h
@@ -15,7 +15,7 @@ There are platform dependent and general
 #if !defined(WIN32)
 #include <stdint.h>
    typedef uint8_t            BYTE;
-   typedef int8_t             TSS_BOOL;
+   typedef uint8_t            TSS_BOOL;
    typedef uint16_t           UINT16;
    typedef uint32_t           UINT32;
    typedef uint64_t           UINT64;
