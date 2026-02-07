--- src/las2txt.cpp.orig	2025-01-19 14:35:25 UTC
+++ src/las2txt.cpp
@@ -570,7 +570,7 @@ static void parse_extended_flags(char *parse_string)
 static void parse_extended_flags(char *parse_string)
 {
   const char *extended_flags[] = {"(HSV)", "(HSL)", "(hsv)", "(hsl)"};
-  const char replacement_codes[] = {HSV255, HSL255, HSV, HSL};
+  const signed char replacement_codes[] = {HSV255, HSL255, HSV, HSL};
   I32 nflags = (I32)(sizeof(extended_flags) / sizeof(char*));
 
   for (I32 i = 0; i < nflags; i++)
