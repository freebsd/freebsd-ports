--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Wed Mar 17 02:08:01 2004
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Wed Mar 17 02:08:15 2004
@@ -65,7 +65,8 @@
 
 #include <gdk/gdkx.h>
 #include <freetype/tttables.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #define FORCE_PR_LOG
 #include "prlog.h"
