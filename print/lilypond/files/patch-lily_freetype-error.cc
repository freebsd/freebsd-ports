--- lily/freetype-error.cc.orig	2013-12-16 15:18:38.000000000 +0100
+++ lily/freetype-error.cc	2013-12-16 15:19:06.000000000 +0100
@@ -31,7 +31,8 @@
   const char *err_msg;
 } ft_errors[] =
 
-#include <freetype/fterrors.h>
+#include <ft2build.h>
+#include FT_ERRORS_H
 
   ;
 
