--- ttf.h.orig	Wed Mar 13 19:16:38 2002
+++ ttf.h	Sun Mar 21 22:30:16 2004
@@ -3,15 +3,18 @@
 #define TTF_H__
 
 #include <string>
-#include "freetype/freetype.h"
-#include "freetype/tttables.h"
-#include "freetype/ftsnames.h"
-#include "freetype/ttnameid.h"
-#include "freetype/fterrors.h"
-#include "freetype/ftmodule.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_TRUETYPE_TABLES_H
+#include FT_SFNT_NAMES_H
+#include FT_TRUETYPE_IDS_H
+#include FT_ERRORS_H
+#include FT_MODULE_H
 
 #include "util.h"
 #include "encoding.h"
+
+using namespace std;
 
 namespace ttf {
 
