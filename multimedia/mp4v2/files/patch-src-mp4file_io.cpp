--- src/mp4file_io.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/mp4file_io.cpp
@@ -387,7 +387,7 @@ char* MP4File::ReadCountedString(uint8_t
         charLength = ReadUInt8();
     }
     
-    if (fixedLength && (charLength > fixedLength)) {
+    if (fixedLength && (charLength > fixedLength - 1)) {
         /*
          * The counted length of this string is greater than the
          * maxiumum fixed length, so truncate the string to the
@@ -397,7 +397,7 @@ char* MP4File::ReadCountedString(uint8_t
          * a non counted string has been used in the place of a
          * counted string).
          */  
-        WARNING(charLength > fixedLength);
+        WARNING(charLength > fixedLength - 1);
         charLength = fixedLength - 1U;
     }
 
