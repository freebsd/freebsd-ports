--- installer/gf-pfb.c.orig	Mon Mar 22 23:33:20 2004
+++ installer/gf-pfb.c	Mon Mar 22 23:33:36 2004
@@ -12,7 +12,8 @@
 #include <fcntl.h>
 #include <string.h>
 #include <ctype.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include "gf-pfb.h"
 
 #define noVERBOSE
