--- src/subs_edit_box.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/subs_edit_box.cpp	2014-08-06 00:09:49.000000000 +0900
@@ -69,6 +69,13 @@
 #include <wx/sizer.h>
 #include <wx/spinctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace std {
 	template <typename T>
 	struct hash<boost::flyweight<T>> {
@@ -354,7 +361,7 @@
 	if (type & AssFile::COMMIT_DIAG_META) {
 		layer->SetValue(line->Layer);
 		for (size_t i = 0; i < margin.size(); ++i)
-			change_value(margin[i], std::to_wstring(line->Margin[i]));
+			change_value(margin[i], TO_WSTRING(line->Margin[i]));
 		comment_box->SetValue(line->Comment);
 		style_box->Select(style_box->FindString(to_wx(line->Style)));
 		active_style = line ? c->ass->GetStyle(line->Style) : nullptr;
@@ -623,7 +630,7 @@
 	if (OPT_GET("Subtitle/Character Counter/Ignore Punctuation")->GetBool())
 		ignore |= agi::IGNORE_PUNCTUATION;
 	size_t length = agi::MaxLineLength(text, ignore);
-	char_count->SetValue(std::to_wstring(length));
+	char_count->SetValue(TO_WSTRING(length));
 	size_t limit = (size_t)OPT_GET("Subtitle/Character Limit")->GetInt();
 	if (limit && length > limit)
 		char_count->SetBackgroundColour(to_wx(OPT_GET("Colour/Subtitle/Syntax/Background/Error")->GetColor()));
