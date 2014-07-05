--- src/subs_edit_box.cpp.orig
+++ src/subs_edit_box.cpp
@@ -71,6 +71,13 @@
 #include <wx/sizer.h>
 #include <wx/spinctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace {
 
 /// Work around wxGTK's fondness for generating events from ChangeValue
@@ -324,7 +331,7 @@
 	if (type & AssFile::COMMIT_DIAG_META) {
 		layer->SetValue(line->Layer);
 		for (size_t i = 0; i < margin.size(); ++i)
-			change_value(margin[i], std::to_wstring(line->Margin[i]));
+			change_value(margin[i], TO_WSTRING(line->Margin[i]));
 		comment_box->SetValue(line->Comment);
 		style_box->Select(style_box->FindString(to_wx(line->Style)));
 
