--- OpenTypeUtilities.cpp.orig	2017-02-10 20:28:02.186321000 -0800
+++ OpenTypeUtilities.cpp	2017-02-10 20:34:22.986633000 -0800
@@ -27,6 +27,7 @@
 
 #include <string.h>
 #include <vector>
+#include <cstddef>
 
 #ifndef _MSC_VER
 # include <stdint.h>
@@ -178,7 +179,7 @@
     dst[i] = 0;
 }
 
-bool getEOTHeader(unsigned char* fontData, size_t fontSize, vector<uint8_t>& eotHeader, size_t& overlayDst, size_t& overlaySrc, size_t& overlayLength)
+bool getEOTHeader(unsigned char* fontData, size_t fontSize, vector<uint8_t>&eotHeader, size_t&overlayDst, size_t&overlaySrc, size_t&overlayLength)
 {
     overlayDst = 0;
     overlaySrc = 0;
