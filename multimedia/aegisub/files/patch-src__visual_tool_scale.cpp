--- src/visual_tool_scale.cpp.orig
+++ src/visual_tool_scale.cpp
@@ -26,6 +26,13 @@
 
 #include "utils.h"
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 VisualToolScale::VisualToolScale(VideoDisplay *parent, agi::Context *context)
 : VisualTool<VisualDraggableFeature>(parent, context)
 {
@@ -106,8 +113,8 @@
 	if (ctrl_down)
 		scale = scale.Round(25.f);
 
-	SetSelectedOverride("\\fscx", std::to_string((int)scale.X()));
-	SetSelectedOverride("\\fscy", std::to_string((int)scale.Y()));
+	SetSelectedOverride("\\fscx", TO_STRING((int)scale.X()));
+	SetSelectedOverride("\\fscy", TO_STRING((int)scale.Y()));
 }
 
 void VisualToolScale::DoRefresh() {
