--- core/DesktopEditor/fontengine/TextShaper.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/fontengine/TextShaper.cpp
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
