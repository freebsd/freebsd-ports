--- core/DesktopEditor/fontengine/TextShaper.cpp.orig	2022-09-27 21:25:17.640269000 +0200
+++ core/DesktopEditor/fontengine/TextShaper.cpp	2022-09-27 21:21:12.793630000 +0200
@@ -649,9 +649,9 @@ namespace NSShaper
 
 #ifdef SUPPORT_HARFBUZZ_SHAPER
 
-#include <hb.h>
-#include <hb-ft.h>
-#include <hb-ot.h>
+#include <harfbuzz/hb.h>
+#include <harfbuzz/hb-ft.h>
+#include <harfbuzz/hb-ot.h>
 
 namespace NSShaper
 {
