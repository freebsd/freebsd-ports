--- SoObjects/SOGo/NSString+Utilities.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/NSString+Utilities.m
@@ -309,7 +309,7 @@ static int cssEscapingCount;
           c == 0xD ||
           (c >= 0x20 && c <= 0xD7FF) ||
           (c >= 0xE000 && c <= 0xFFFD) ||
-          (c >= 0x10000 && c <= 0x10FFFF))
+          (c >= (unichar)0x10000 && c <= (unichar)0x10FFFF))
         {
           *(start+j) = c;
           j++;
