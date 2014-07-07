--- src/command/video.cpp.orig
+++ src/command/video.cpp
@@ -67,6 +67,13 @@
 #include <wx/msgdlg.h>
 #include <wx/textdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x) 
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace {
 	using cmd::Command;
 
@@ -119,7 +126,7 @@
 		std::string value = from_wx(wxGetTextFromUser(
 			_("Enter aspect ratio in either:\n  decimal (e.g. 2.35)\n  fractional (e.g. 16:9)\n  specific resolution (e.g. 853x480)"),
 			_("Enter aspect ratio"),
-			std::to_wstring(c->videoController->GetAspectRatioValue())));
+			TO_WSTRING(c->videoController->GetAspectRatioValue())));
 		if (value.empty()) return;
 
 		double numval = 0;
