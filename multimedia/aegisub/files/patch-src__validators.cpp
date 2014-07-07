--- src/validators.cpp.orig
+++ src/validators.cpp
@@ -27,6 +27,13 @@
 #include <wx/combobox.h>
 #include <wx/textctrl.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 namespace {
 std::string new_value(wxTextCtrl *ctrl, int chr) {
 	long from, to;
@@ -57,7 +64,7 @@
 }
 
 bool IntValidator::TransferToWindow() {
-	static_cast<wxTextCtrl *>(GetWindow())->SetValue(std::to_wstring(value));
+	static_cast<wxTextCtrl *>(GetWindow())->SetValue(TO_WSTRING(value));
 	return true;
 }
 
