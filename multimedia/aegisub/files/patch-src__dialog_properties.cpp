--- src/dialog_properties.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/dialog_properties.cpp	2014-08-05 20:27:38.000000000 +0900
@@ -47,6 +47,15 @@
 #include <wx/stattext.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace {
 class DialogProperties {
 	wxDialog d;
@@ -186,7 +195,7 @@
 
 	count += SetInfoIfDifferent("PlayResX", from_wx(ResX->GetValue()));
 	count += SetInfoIfDifferent("PlayResY", from_wx(ResY->GetValue()));
-	count += SetInfoIfDifferent("WrapStyle", std::to_string(WrapStyle->GetSelection()));
+	count += SetInfoIfDifferent("WrapStyle", TO_STRING(WrapStyle->GetSelection()));
 	count += SetInfoIfDifferent("ScaledBorderAndShadow", ScaleBorder->GetValue() ? "yes" : "no");
 	count += SetInfoIfDifferent("YCbCr Matrix", from_wx(YCbCrMatrix->GetValue()));
 
@@ -204,8 +213,8 @@
 }
 
 void DialogProperties::OnSetFromVideo(wxCommandEvent &) {
-	ResX->SetValue(std::to_wstring(c->project->VideoProvider()->GetWidth()));
-	ResY->SetValue(std::to_wstring(c->project->VideoProvider()->GetHeight()));
+	ResX->SetValue(TO_WSTRING(c->project->VideoProvider()->GetWidth()));
+	ResY->SetValue(TO_WSTRING(c->project->VideoProvider()->GetHeight()));
 }
 }
 
