--- src/3rdparty/chromium/third_party/modp_b64/modp_b64.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/modp_b64/modp_b64.cc
@@ -118,7 +118,7 @@ size_t modp_b64_encode(char* dest, const char* str, si
 }
 
 #ifdef WORDS_BIGENDIAN   /* BIG ENDIAN -- SUN / IBM / MOTOROLA */
-int modp_b64_decode(char* dest, const char* src, int len)
+size_t modp_b64_decode(char* dest, const char* src, size_t len)
 {
     if (len == 0) return 0;
 
