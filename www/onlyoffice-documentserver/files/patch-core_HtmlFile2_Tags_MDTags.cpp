--- core/HtmlFile2/Tags/MDTags.cpp.orig	2026-10-11 14:54:04 UTC
+++ core/HtmlFile2/Tags/MDTags.cpp
@@ -48,7 +48,7 @@
 #include "../../DesktopEditor/graphics/pro/Graphics.h"
 #include "../../DesktopEditor/raster/BgraFrame.h"
 
-#include "../../Common/3dParty/html/gumbo-parser/src/gumbo.h"
+#include <gumbo.h>
 
 namespace HTML
 {
