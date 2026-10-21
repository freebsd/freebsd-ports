--- core/HtmlFile2/Tags/OOXMLTags.cpp.orig	2026-10-11 14:54:04 UTC
+++ core/HtmlFile2/Tags/OOXMLTags.cpp
@@ -44,7 +44,7 @@
 #include "../../DesktopEditor/common/File.h"
 #include "../../DesktopEditor/common/Path.h"
 
-#include "../../Common/3dParty/html/gumbo-parser/src/gumbo.h"
+#include <gumbo.h>
 
 namespace HTML
 {
