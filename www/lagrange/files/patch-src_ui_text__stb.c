--- src/ui/text_stb.c.orig	2025-01-01 16:30:13 UTC
+++ src/ui/text_stb.c
@@ -82,7 +82,7 @@ - Caching FontRuns is quite effective, but there is st
 #endif
 
 #define STB_TRUETYPE_IMPLEMENTATION
-#include "../stb_truetype.h"
+#include "stb_truetype.h"
 
 iDeclareType(Font)
 iDeclareType(Glyph)
