--- src/dialog_shift_times.cpp.orig
+++ src/dialog_shift_times.cpp
@@ -56,6 +56,13 @@
 #include <wx/sizer.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 static wxString get_history_string(json::Object &obj) {
 	wxString filename = to_wx(obj["filename"]);
 	if (filename.empty())
@@ -87,7 +94,7 @@
 			int beg = (int64_t)(*it)["start"];
 			int end = (int64_t)(*it)["end"];
 			if (beg == end)
-				lines += std::to_wstring(beg);
+				lines += TO_WSTRING(beg);
 			else
 				lines += wxString::Format("%d-%d", beg, end);
 			if (it + 1 != sel.end())
