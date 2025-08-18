--- core/DesktopEditor/freetype-2.10.4/src/autofit/afshaper.h.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/freetype-2.10.4/src/autofit/afshaper.h
@@ -25,9 +25,9 @@
 
 #ifdef FT_CONFIG_OPTION_USE_HARFBUZZ
 
-#include <hb.h>
-#include <hb-ot.h>
-#include <hb-ft.h>
+#include <harfbuzz/hb.h>
+#include <harfbuzz/hb-ot.h>
+#include <harfbuzz/hb-ft.h>
 
 #endif
 
