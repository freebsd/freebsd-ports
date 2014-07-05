--- src/resolution_resampler.cpp.orig
+++ src/resolution_resampler.cpp
@@ -29,9 +29,15 @@
 
 #include <algorithm>
 #include <boost/algorithm/string/predicate.hpp>
-#include <boost/lexical_cast.hpp>
 #include <functional>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 enum {
 	LEFT = 0,
 	RIGHT = 1,
@@ -175,8 +181,8 @@
 	for (auto& line : ass->Line)
 		resample_line(&state, line);
 
-	ass->SetScriptInfo("PlayResX", std::to_string(settings.script_x));
-	ass->SetScriptInfo("PlayResY", std::to_string(settings.script_y));
+	ass->SetScriptInfo("PlayResX", TO_STRING(settings.script_x));
+	ass->SetScriptInfo("PlayResY", TO_STRING(settings.script_y));
 
 	ass->Commit(_("resolution resampling"), AssFile::COMMIT_SCRIPTINFO | AssFile::COMMIT_DIAG_FULL);
 }
