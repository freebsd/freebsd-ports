--- lily/open-type-font.cc.orig	2013-12-16 15:54:16.000000000 +0100
+++ lily/open-type-font.cc	2013-12-16 15:54:45.000000000 +0100
@@ -23,7 +23,8 @@
 
 using namespace std;
 
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 
 #include "dimensions.hh"
 #include "international.hh"
