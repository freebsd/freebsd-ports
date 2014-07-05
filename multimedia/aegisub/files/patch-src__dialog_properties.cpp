--- src/dialog_properties.cpp.orig
+++ src/dialog_properties.cpp
@@ -54,6 +54,15 @@
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
 DialogProperties::DialogProperties(agi::Context *c)
 : wxDialog(c->parent, -1, _("Script Properties"))
 , c(c)
@@ -145,7 +154,7 @@
 
 	count += SetInfoIfDifferent("PlayResX", from_wx(ResX->GetValue()));
 	count += SetInfoIfDifferent("PlayResY", from_wx(ResY->GetValue()));
-	count += SetInfoIfDifferent("WrapStyle", std::to_string(WrapStyle->GetSelection()));
+	count += SetInfoIfDifferent("WrapStyle", TO_STRING(WrapStyle->GetSelection()));
 	count += SetInfoIfDifferent("ScaledBorderAndShadow", ScaleBorder->GetValue() ? "yes" : "no");
 
 	if (count) c->ass->Commit(_("property changes"), AssFile::COMMIT_SCRIPTINFO);
@@ -162,6 +171,6 @@
 }
 
 void DialogProperties::OnSetFromVideo(wxCommandEvent &) {
-	ResX->SetValue(std::to_wstring(c->videoController->GetWidth()));
-	ResY->SetValue(std::to_wstring(c->videoController->GetHeight()));
+	ResX->SetValue(TO_WSTRING(c->videoController->GetWidth()));
+	ResY->SetValue(TO_WSTRING(c->videoController->GetHeight()));
 }
