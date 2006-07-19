--- ttf.h.orig	Wed Jul 19 11:36:47 2006
+++ ttf.h	Wed Jul 19 11:36:50 2006
@@ -3,16 +3,19 @@
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
 
+using namespace std;
+
 namespace ttf {
 
     class Face {
@@ -49,7 +52,7 @@
 	TT_Postscript	    *post;
 	std::string	    FileName;
     };
-};
+}
 
 #endif /* TTF_H__ */
 
