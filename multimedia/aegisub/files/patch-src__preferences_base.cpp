--- src/preferences_base.cpp.orig
+++ src/preferences_base.cpp
@@ -42,6 +42,13 @@
 #include <wx/stattext.h>
 #include <wx/treebook.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 #define OPTION_UPDATER(type, evttype, opt, body)                            \
 	class type {                                                            \
 		std::string name;                                                   \
@@ -126,7 +133,7 @@
 		}
 
 		case agi::OptionValue::Type_Int: {
-			wxSpinCtrl *sc = new wxSpinCtrl(this, -1, std::to_wstring((int)opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetInt());
+			wxSpinCtrl *sc = new wxSpinCtrl(this, -1, TO_WSTRING((int)opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetInt());
 			sc->Bind(wxEVT_SPINCTRL, IntUpdater(opt_name, parent));
 			Add(flex, name, sc);
 			return sc;
@@ -240,7 +247,7 @@
 	font_name->SetMinSize(wxSize(160, -1));
 	font_name->Bind(wxEVT_TEXT, StringUpdater(face_opt->GetName().c_str(), parent));
 
-	wxSpinCtrl *font_size = new wxSpinCtrl(this, -1, std::to_wstring((int)size_opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 3, 42, size_opt->GetInt());
+	wxSpinCtrl *font_size = new wxSpinCtrl(this, -1, TO_WSTRING((int)size_opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 3, 42, size_opt->GetInt());
 	font_size->Bind(wxEVT_SPINCTRL, IntUpdater(size_opt->GetName().c_str(), parent));
 
 	wxButton *pick_btn = new wxButton(this, -1, _("Choose..."));
