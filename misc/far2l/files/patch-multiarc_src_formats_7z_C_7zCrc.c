--- multiarc/src/formats/7z/C/7zCrc.c.orig	2023-01-14 23:53:02 UTC
+++ multiarc/src/formats/7z/C/7zCrc.c
@@ -86,7 +86,7 @@ UInt32 MY_FAST_CALL CrcUpdateT1(UInt32 v, const void *
       #if !defined(__ARM_FEATURE_CRC32)
         #define __ARM_FEATURE_CRC32 1
           #if (!defined(__clang__) || (__clang_major__ > 3)) // fix these numbers
-            #define ATTRIB_CRC __attribute__((__target__("arch=armv8-a+crc")))
+            #define ATTRIB_CRC __attribute__((__target__("crc")))
           #endif
       #endif
       #if defined(__ARM_FEATURE_CRC32)
