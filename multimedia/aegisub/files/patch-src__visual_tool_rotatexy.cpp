--- src/visual_tool_rotatexy.cpp.orig
+++ src/visual_tool_rotatexy.cpp
@@ -25,6 +25,8 @@
 #include <boost/format.hpp>
 #include <cmath>
 
+#include <wx/colour.h>
+
 VisualToolRotateXY::VisualToolRotateXY(VideoDisplay *parent, agi::Context *context)
 : VisualTool<VisualDraggableFeature>(parent, context)
 {
