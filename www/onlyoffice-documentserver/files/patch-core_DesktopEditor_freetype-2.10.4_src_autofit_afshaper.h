--- core/DesktopEditor/freetype-2.10.4/src/autofit/afshaper.h.orig	2022-09-27 21:25:17.639848000 +0200
+++ core/DesktopEditor/freetype-2.10.4/src/autofit/afshaper.h	2022-09-27 21:21:29.147465000 +0200
@@ -25,9 +25,9 @@
 
 #ifdef FT_CONFIG_OPTION_USE_HARFBUZZ
 
-#include <hb.h>
-#include <hb-ot.h>
-#include <hb-ft.h>
+#include <harfbuzz/hb.h>
+#include <harfbuzz/hb-ot.h>
+#include <harfbuzz/hb-ft.h>
 
 #endif
 
