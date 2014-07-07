--- src/subs_preview.cpp.orig
+++ src/subs_preview.cpp
@@ -48,6 +48,13 @@
 #include <wx/dcclient.h>
 #include <wx/msgdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 SubtitlesPreview::SubtitlesPreview(wxWindow *parent, wxSize size, int winStyle, agi::Color col)
 : wxWindow(parent, -1, wxDefaultPosition, size, winStyle)
 , style(new AssStyle)
@@ -141,8 +148,8 @@
 			"No subtitles provider", wxOK | wxICON_ERROR | wxCENTER);
 	}
 
-	sub_file->SetScriptInfo("PlayResX", std::to_string(w));
-	sub_file->SetScriptInfo("PlayResY", std::to_string(h));
+	sub_file->SetScriptInfo("PlayResX", TO_STRING(w));
+	sub_file->SetScriptInfo("PlayResY", TO_STRING(h));
 
 	UpdateBitmap();
 }
