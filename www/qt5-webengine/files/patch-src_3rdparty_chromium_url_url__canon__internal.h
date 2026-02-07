--- src/3rdparty/chromium/url/url_canon_internal.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/url/url_canon_internal.h
@@ -305,9 +305,9 @@ inline bool Is8BitChar(base::char16 c) {
   return c <= 255;
 }
 
-template<typename CHAR>
+template<typename CHAR, typename DST>
 inline bool DecodeEscaped(const CHAR* spec, int* begin, int end,
-                          unsigned char* unescaped_value) {
+                          DST* unescaped_value) {
   if (*begin + 3 > end ||
       !Is8BitChar(spec[*begin + 1]) || !Is8BitChar(spec[*begin + 2])) {
     // Invalid escape sequence because there's not enough room, or the
