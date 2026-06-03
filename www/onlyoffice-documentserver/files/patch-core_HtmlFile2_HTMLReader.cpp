--- core/HtmlFile2/HTMLReader.cpp.orig	2026-02-23 16:20:47 UTC
+++ core/HtmlFile2/HTMLReader.cpp
@@ -13,7 +13,7 @@
 #include "Writers/MDWriter.h"
 #include "Tags/MDTags.h"
 
-#include "../Common/3dParty/html/gumbo-parser/src/gumbo.h"
+#include <gumbo.h>
 #include "src/StringFinder.h"
 
 #include <boost/tuple/tuple.hpp>
