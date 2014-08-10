--- src/validators.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/validators.cpp	2014-08-06 00:12:26.000000000 +0900
@@ -25,6 +25,13 @@
 #include <wx/spinctrl.h>
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
@@ -55,7 +62,7 @@
 }
 
 bool IntValidator::TransferToWindow() {
-	static_cast<wxTextCtrl *>(GetWindow())->SetValue(std::to_wstring(value));
+	static_cast<wxTextCtrl *>(GetWindow())->SetValue(TO_WSTRING(value));
 	return true;
 }
 
@@ -132,7 +139,7 @@
 }
 
 bool DoubleValidator::TransferToWindow() {
-	auto str = std::to_wstring(*value);
+	auto str = TO_WSTRING(*value);
 	if (decimal_sep != '.')
 		std::replace(str.begin(), str.end(), L'.', decimal_sep);
 	if (str.find(decimal_sep) != str.npos) {
