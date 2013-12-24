--- lily/ttf.cc.orig	2013-12-16 15:48:08.000000000 +0100
+++ lily/ttf.cc	2013-12-16 15:48:37.000000000 +0100
@@ -20,7 +20,8 @@
 #include <cstdio>
 #include "freetype.hh"
 
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 
 #include "international.hh"
 #include "memory-stream.hh"
