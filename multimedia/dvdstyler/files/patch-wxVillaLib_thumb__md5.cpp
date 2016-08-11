--- wxVillaLib/thumb_md5.cpp.orig	2014-02-25 11:08:27 UTC
+++ wxVillaLib/thumb_md5.cpp
@@ -334,8 +334,8 @@ char* escape_string(const char *string)
 
         if (!ACCEPTABLE_CHAR (c)) {
             *q++ = HEX_ESCAPE; /* means hex coming */
-            *q++ = hex[c >> 4];
-            *q++ = hex[c & 15];
+            *q++ = ::hex[c >> 4];
+            *q++ = ::hex[c & 15];
         } else {
             *q++ = c;
         }
