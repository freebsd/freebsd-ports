--- src/dialog_style_editor.cpp.orig
+++ src/dialog_style_editor.cpp
@@ -62,6 +62,13 @@
 #include <wx/sizer.h>
 #include <wx/stattext.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 /// Style rename helper that walks a file searching for a style and optionally
 /// updating references to it
 class StyleRenamer {
@@ -160,7 +167,7 @@
 	SetIcon(GETICON(style_toolbutton_16));
 
 	// Prepare control values
-	wxString EncodingValue = std::to_wstring(style->encoding);
+	wxString EncodingValue = TO_WSTRING(style->encoding);
 	wxString alignValues[9] = { "7", "8", "9", "4", "5", "6", "1", "2", "3" };
 
 	// Encoding options
