--- src/command/edit.cpp.orig
+++ src/command/edit.cpp
@@ -68,6 +68,13 @@
 #include <wx/clipbrd.h>
 #include <wx/fontdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x) 
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace {
 	using namespace boost::adaptors;
 	using cmd::Command;
@@ -450,13 +457,13 @@
 		if (font.GetFaceName() != startfont.GetFaceName())
 			set_tag(line, blocks, "\\fn", from_wx(font.GetFaceName()), sel_start, sel_end);
 		if (font.GetPointSize() != startfont.GetPointSize())
-			set_tag(line, blocks, "\\fs", std::to_string(font.GetPointSize()), sel_start, sel_end);
+			set_tag(line, blocks, "\\fs", TO_STRING(font.GetPointSize()), sel_start, sel_end);
 		if (font.GetWeight() != startfont.GetWeight())
-			set_tag(line, blocks, "\\b", std::to_string(font.GetWeight() == wxFONTWEIGHT_BOLD), sel_start, sel_end);
+			set_tag(line, blocks, "\\b", TO_STRING(font.GetWeight() == wxFONTWEIGHT_BOLD), sel_start, sel_end);
 		if (font.GetStyle() != startfont.GetStyle())
-			set_tag(line, blocks, "\\i", std::to_string(font.GetStyle() == wxFONTSTYLE_ITALIC), sel_start, sel_end);
+			set_tag(line, blocks, "\\i", TO_STRING(font.GetStyle() == wxFONTSTYLE_ITALIC), sel_start, sel_end);
 		if (font.GetUnderlined() != startfont.GetUnderlined())
-			set_tag(line, blocks, "\\i", std::to_string(font.GetUnderlined()), sel_start, sel_end);
+			set_tag(line, blocks, "\\i", TO_STRING(font.GetUnderlined()), sel_start, sel_end);
 
 		commit_text(c, _("set font"), sel_start, sel_end);
 	}
@@ -711,7 +718,7 @@
 }
 
 static void combine_karaoke(AssDialogue *first, AssDialogue *second) {
-	first->Text = first->Text.get() + "{\\k" + std::to_string((second->Start - first->End) / 10) + "}" + second->Text.get();
+	first->Text = first->Text.get() + "{\\k" + TO_STRING((second->Start - first->End) / 10) + "}" + second->Text.get();
 }
 
 static void combine_concat(AssDialogue *first, AssDialogue *second) {
