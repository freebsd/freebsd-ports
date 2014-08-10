--- src/dialog_style_editor.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/dialog_style_editor.cpp	2014-08-05 20:30:35.000000000 +0900
@@ -61,6 +61,13 @@
 #include <wx/spinctrl.h>
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
@@ -166,7 +173,7 @@
 	};
 
 	// Prepare control values
-	wxString EncodingValue = std::to_wstring(style->encoding);
+	wxString EncodingValue = TO_WSTRING(style->encoding);
 	wxString alignValues[9] = { "7", "8", "9", "4", "5", "6", "1", "2", "3" };
 
 	// Encoding options
@@ -197,7 +204,7 @@
 		new ColourButton(this, wxSize(55, 16), true, style->shadow, ColorValidator(&work->shadow))
 	};
 	for (int i = 0; i < 3; i++)
-		margin[i] = new wxSpinCtrl(this, -1, std::to_wstring(style->Margin[i]),
+		margin[i] = new wxSpinCtrl(this, -1, TO_WSTRING(style->Margin[i]),
 		                           wxDefaultPosition, wxSize(60, -1),
 		                           wxSP_ARROW_KEYS, 0, 9999, style->Margin[i]);
 
