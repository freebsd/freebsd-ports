--- core/DesktopEditor/fontengine/js/cpp/text.cpp.orig	2022-09-27 21:25:17.640548000 +0200
+++ core/DesktopEditor/fontengine/js/cpp/text.cpp	2022-09-27 21:22:11.216341000 +0200
@@ -532,9 +532,9 @@ WASM_EXPORT unsigned char* ASC_FT_Get_Glyph_Render_Buf
 // ------------------------------------------------------------
 
 // HARFBUZZ
-#include <hb.h>
-#include <hb-ft.h>
-#include <hb-ot.h>
+#include <harfbuzz/hb.h>
+#include <harfbuzz/hb-ft.h>
+#include <harfbuzz/hb-ot.h>
 
 #define g_userfeatures_count 5
 hb_feature_t g_userfeatures[g_userfeatures_count];
