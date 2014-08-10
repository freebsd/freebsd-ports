--- src/timeedit_ctrl.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/timeedit_ctrl.cpp	2014-08-05 08:03:02.000000000 +0900
@@ -48,6 +48,13 @@
 
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
@@ -113,7 +120,7 @@
 
 void TimeEdit::UpdateText() {
 	if (byFrame)
-		ChangeValue(std::to_wstring(c->project->Timecodes().FrameAtTime(time, isEnd ? agi::vfr::END : agi::vfr::START)));
+		ChangeValue(TO_WSTRING(c->project->Timecodes().FrameAtTime(time, isEnd ? agi::vfr::END : agi::vfr::START)));
 	else
 		ChangeValue(to_wx(time.GetAssFormatted()));
 }
