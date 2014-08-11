--- src/resolution_resampler.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/resolution_resampler.cpp	2014-08-05 07:58:45.000000000 +0900
@@ -32,6 +32,13 @@
 #include <cmath>
 #include <wx/intl.h>
 
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
@@ -281,8 +288,8 @@
 	for (auto& line : ass->Events)
 		resample_line(&state, line);
 
-	ass->SetScriptInfo("PlayResX", std::to_string(settings.dest_x));
-	ass->SetScriptInfo("PlayResY", std::to_string(settings.dest_y));
+	ass->SetScriptInfo("PlayResX", TO_STRING(settings.dest_x));
+	ass->SetScriptInfo("PlayResY", TO_STRING(settings.dest_y));
 	ass->SetScriptInfo("YCbCr Matrix", MatrixToString(settings.dest_matrix));
 
 	ass->Commit(_("resolution resampling"), AssFile::COMMIT_SCRIPTINFO | AssFile::COMMIT_DIAG_FULL);
