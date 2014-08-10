--- src/preferences_base.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/preferences_base.cpp	2014-08-05 07:56:10.000000000 +0900
@@ -40,6 +40,13 @@
 
 #undef Bool
 
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
@@ -124,14 +131,14 @@
 		}
 
 		case agi::OptionType::Int: {
-			auto sc = new wxSpinCtrl(this, -1, std::to_wstring((int)opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetInt());
+			auto sc = new wxSpinCtrl(this, -1, TO_WSTRING((int)opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetInt());
 			sc->Bind(wxEVT_SPINCTRL, IntUpdater(opt_name, parent));
 			Add(flex, name, sc);
 			return sc;
 		}
 
 		case agi::OptionType::Double: {
-			auto scd = new wxSpinCtrlDouble(this, -1, std::to_wstring(opt->GetDouble()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetDouble(), inc);
+			auto scd = new wxSpinCtrlDouble(this, -1, TO_WSTRING(opt->GetDouble()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, min, max, opt->GetDouble(), inc);
 			scd->Bind(wxEVT_SPINCTRL, DoubleUpdater(opt_name, parent));
 			Add(flex, name, scd);
 			return scd;
@@ -238,7 +245,7 @@
 	font_name->SetMinSize(wxSize(160, -1));
 	font_name->Bind(wxEVT_TEXT, StringUpdater(face_opt->GetName().c_str(), parent));
 
-	auto font_size = new wxSpinCtrl(this, -1, std::to_wstring((int)size_opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 3, 42, size_opt->GetInt());
+	auto font_size = new wxSpinCtrl(this, -1, TO_WSTRING((int)size_opt->GetInt()), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 3, 42, size_opt->GetInt());
 	font_size->Bind(wxEVT_SPINCTRL, IntUpdater(size_opt->GetName().c_str(), parent));
 
 	auto pick_btn = new wxButton(this, -1, _("Choose..."));
