--- libgnomeprint/parseTT.c.orig	Mon Mar 22 23:29:57 2004
+++ libgnomeprint/parseTT.c	Mon Mar 22 23:30:15 2004
@@ -107,7 +107,8 @@
 #include <config.h>
 
 #include <parseTT.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftglyph.h>
 #include <freetype/ftoutln.h>
 #include <stdio.h>
