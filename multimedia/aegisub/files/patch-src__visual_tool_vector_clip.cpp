--- src/visual_tool_vector_clip.cpp.orig
+++ src/visual_tool_vector_clip.cpp
@@ -36,6 +36,13 @@
 #include <boost/range/algorithm/set_algorithm.hpp>
 #include <wx/toolbar.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 /// Button IDs
 enum {
 	BUTTON_DRAG = 1300,
@@ -208,7 +215,7 @@
 void VisualToolVectorClip::Save() {
 	std::string value = "(";
 	if (spline.GetScale() != 1)
-		value += std::to_string(spline.GetScale()) + ",";
+		value += TO_STRING(spline.GetScale()) + ",";
 	value += spline.EncodeToAss() + ")";
 
 	for (auto line : c->selectionController->GetSelectedSet()) {
