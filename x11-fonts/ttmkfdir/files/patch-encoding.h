--- encoding.h.orig	Tue Mar 12 15:41:27 2002
+++ encoding.h	Sun Mar 21 22:35:15 2004
@@ -6,7 +6,8 @@
 #include <map>
 #include <string>
 
-#include "freetype/freetype.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "util.h"
 
