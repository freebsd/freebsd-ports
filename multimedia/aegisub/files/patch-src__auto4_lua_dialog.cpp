--- src/auto4_lua_dialog.cpp.orig
+++ src/auto4_lua_dialog.cpp
@@ -60,6 +60,13 @@
 #include <wx/stattext.h>
 #include <wx/valgen.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 using namespace agi::lua;
 namespace {
 	inline void get_if_right_type(lua_State *L, std::string &def) {
@@ -249,7 +256,7 @@
 			}
 
 			bool CanSerialiseValue() const override  { return true; }
-			std::string SerialiseValue() const override { return std::to_string(value); }
+			std::string SerialiseValue() const override { return TO_STRING(value); }
 			void UnserialiseValue(const std::string &serialised) override { value = atoi(serialised.c_str()); }
 
 			wxControl *Create(wxWindow *parent) override {
@@ -287,7 +294,7 @@
 			}
 
 			bool CanSerialiseValue() const override { return true; }
-			std::string SerialiseValue() const override { return std::to_string(value); }
+			std::string SerialiseValue() const override { return TO_STRING(value); }
 			void UnserialiseValue(const std::string &serialised) override { value = atof(serialised.c_str()); }
 
 			wxControl *Create(wxWindow *parent) override {
