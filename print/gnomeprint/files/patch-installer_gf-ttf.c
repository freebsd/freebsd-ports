--- installer/gf-ttf.c.orig	Mon Mar 22 23:34:10 2004
+++ installer/gf-ttf.c	Mon Mar 22 23:34:23 2004
@@ -32,7 +32,8 @@
 #include <fcntl.h>
 #include <string.h>
 #include <ctype.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "gf-ttf.h"
 
