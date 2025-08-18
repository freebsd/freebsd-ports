--- core/DesktopEditor/fontengine/js/cpp/text.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/fontengine/js/cpp/text.cpp
@@ -558,9 +558,9 @@ WASM_EXPORT unsigned char* ASC_FT_Get_Glyph_Render_Buf
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
