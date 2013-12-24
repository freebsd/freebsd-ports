--- lily/pango-font.cc.orig	2013-12-16 15:49:55.000000000 +0100
+++ lily/pango-font.cc	2013-12-16 15:50:46.000000000 +0100
@@ -22,7 +22,8 @@
 #define PANGO_ENABLE_BACKEND
 
 #include <pango/pangoft2.h>
-#include <freetype/ftxf86.h>
+#include <ft2build.h>
+#include FT_XFREE86_H
 
 #include <map>
 #include <cstdio>
