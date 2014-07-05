--- src/timeedit_ctrl.cpp.orig
+++ src/timeedit_ctrl.cpp
@@ -52,6 +52,13 @@
 
 #define TimeEditWindowStyle
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 enum {
 	Time_Edit_Copy = 1320,
 	Time_Edit_Paste
@@ -117,7 +124,7 @@
 
 void TimeEdit::UpdateText() {
 	if (byFrame)
-		ChangeValue(std::to_wstring(c->videoController->FrameAtTime(time, isEnd ? agi::vfr::END : agi::vfr::START)));
+		ChangeValue(TO_WSTRING(c->videoController->FrameAtTime(time, isEnd ? agi::vfr::END : agi::vfr::START)));
 	else
 		ChangeValue(to_wx(time.GetAssFormated()));
 }
