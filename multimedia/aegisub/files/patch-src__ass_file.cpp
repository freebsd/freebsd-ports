--- src/ass_file.cpp.orig
+++ src/ass_file.cpp
@@ -29,6 +29,13 @@
 #include <boost/filesystem/path.hpp>
 #include <cassert>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 AssFile::AssFile() { }
 
 AssFile::~AssFile() {
@@ -42,8 +49,8 @@
 	Info.emplace_back("WrapStyle", "0");
 	Info.emplace_back("ScaledBorderAndShadow", "yes");
 	if (!OPT_GET("Subtitle/Default Resolution/Auto")->GetBool()) {
-		Info.emplace_back("PlayResX", std::to_string(OPT_GET("Subtitle/Default Resolution/Width")->GetInt()));
-		Info.emplace_back("PlayResY", std::to_string(OPT_GET("Subtitle/Default Resolution/Height")->GetInt()));
+		Info.emplace_back("PlayResX", TO_STRING(OPT_GET("Subtitle/Default Resolution/Width")->GetInt()));
+		Info.emplace_back("PlayResY", TO_STRING(OPT_GET("Subtitle/Default Resolution/Height")->GetInt()));
 	}
 	Info.emplace_back("YCbCr Matrix", "None");
 
