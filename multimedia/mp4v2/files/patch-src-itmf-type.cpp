--- src/itmf/type.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/itmf/type.cpp
@@ -284,7 +284,7 @@ namespace {
         { BT_BMP,  "\x42\x4d" },
         { BT_GIF,  "GIF87a" },
         { BT_GIF,  "GIF89a" },
-        { BT_JPEG, "\xff\xd8\xff\xe0" },
+        { BT_JPEG, "\xff\xd8\xff" },
         { BT_PNG,  "\x89\x50\x4e\x47\x0d\x0a\x1a\x0a" },
         { BT_UNDEFINED } // must be last
     };
