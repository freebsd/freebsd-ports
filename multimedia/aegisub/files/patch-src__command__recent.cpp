--- src/command/recent.cpp.orig
+++ src/command/recent.cpp
@@ -44,6 +44,13 @@
 #include <wx/event.h>
 #include <wx/msgdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x) 
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace {
 	using cmd::Command;
 
@@ -124,7 +131,7 @@
 	void operator()(agi::Context *c) {
 		T::operator()(c, id);
 	}
-	mru_wrapper(int id) : id(id) , full_name(T::name() + std::to_string(id)) { }
+	mru_wrapper(int id) : id(id) , full_name(T::name() + TO_STRING(id)) { }
 };
 }
 
