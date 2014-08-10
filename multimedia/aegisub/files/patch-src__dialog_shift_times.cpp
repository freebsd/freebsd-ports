--- src/dialog_shift_times.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/dialog_shift_times.cpp	2014-08-05 20:21:09.000000000 +0900
@@ -48,6 +48,13 @@
 #include <wx/sizer.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace {
 class DialogShiftTimes final : public wxDialog {
 	agi::Context *context;
@@ -118,7 +125,7 @@
 			int beg = (int64_t)range["start"];
 			int end = (int64_t)range["end"];
 			if (beg == end)
-				lines += std::to_wstring(beg);
+				lines += TO_WSTRING(beg);
 			else
 				lines += fmt_wx("%d-%d", beg, end);
 			if (it + 1 != sel.end())
