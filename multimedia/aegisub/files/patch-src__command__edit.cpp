--- src/command/edit.cpp.orig
+++ src/command/edit.cpp
@@ -69,6 +69,13 @@
 #include <wx/fontdlg.h>
 #include <wx/textentry.h>
 
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
@@ -516,13 +523,13 @@
 			if (font.GetFaceName() != startfont.GetFaceName())
 				do_set_tag("\\fn", from_wx(font.GetFaceName()));
 			if (font.GetPointSize() != startfont.GetPointSize())
-				do_set_tag("\\fs", std::to_string(font.GetPointSize()));
+				do_set_tag("\\fs", TO_STRING(font.GetPointSize()));
 			if (font.GetWeight() != startfont.GetWeight())
-				do_set_tag("\\b", std::to_string(font.GetWeight() == wxFONTWEIGHT_BOLD));
+				do_set_tag("\\b", TO_STRING(font.GetWeight() == wxFONTWEIGHT_BOLD));
 			if (font.GetStyle() != startfont.GetStyle())
-				do_set_tag("\\i", std::to_string(font.GetStyle() == wxFONTSTYLE_ITALIC));
+				do_set_tag("\\i", TO_STRING(font.GetStyle() == wxFONTSTYLE_ITALIC));
 			if (font.GetUnderlined() != startfont.GetUnderlined())
-				do_set_tag("\\i", std::to_string(font.GetUnderlined()));
+				do_set_tag("\\i", TO_STRING(font.GetUnderlined()));
 
 			return shift;
 		});
@@ -761,7 +768,7 @@
 }
 
 static void combine_karaoke(AssDialogue *first, AssDialogue *second) {
-	first->Text = first->Text.get() + "{\\k" + std::to_string((second->Start - first->End) / 10) + "}" + second->Text.get();
+	first->Text = first->Text.get() + "{\\k" + TO_STRING((second->Start - first->End) / 10) + "}" + second->Text.get();
 }
 
 static void combine_concat(AssDialogue *first, AssDialogue *second) {
