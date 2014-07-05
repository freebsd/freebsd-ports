--- src/ass_file.cpp.orig
+++ src/ass_file.cpp
@@ -49,6 +49,13 @@
 #include <boost/algorithm/string/case_conv.hpp>
 #include <boost/filesystem/path.hpp>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x) 
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace std {
 	template<>
 	void swap(AssFile &lft, AssFile &rgt) {
@@ -71,8 +78,8 @@
 	Line.push_back(*new AssInfo("WrapStyle", "0"));
 	Line.push_back(*new AssInfo("ScaledBorderAndShadow", "yes"));
 	if (!OPT_GET("Subtitle/Default Resolution/Auto")->GetBool()) {
-		Line.push_back(*new AssInfo("PlayResX", std::to_string(OPT_GET("Subtitle/Default Resolution/Width")->GetInt())));
-		Line.push_back(*new AssInfo("PlayResY", std::to_string(OPT_GET("Subtitle/Default Resolution/Height")->GetInt())));
+		Line.push_back(*new AssInfo("PlayResX", TO_STRING(OPT_GET("Subtitle/Default Resolution/Width")->GetInt())));
+		Line.push_back(*new AssInfo("PlayResY", TO_STRING(OPT_GET("Subtitle/Default Resolution/Height")->GetInt())));
 	}
 	Line.push_back(*new AssInfo("YCbCr Matrix", "None"));
 
