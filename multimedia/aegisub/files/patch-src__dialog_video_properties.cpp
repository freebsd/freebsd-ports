--- src/dialog_video_properties.cpp	2014-07-28 23:29:16.000000000 +0900
+++ /home/jungle/dialog_video_properties.cpp	2014-08-05 20:35:18.000000000 +0900
@@ -27,6 +27,13 @@
 #include <wx/sizer.h>
 #include <wx/stattext.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace {
 enum {
 	MISMATCH_IGNORE,
@@ -103,8 +110,8 @@
 	// If the script resolution hasn't been set at all just force it to the
 	// video resolution
 	if (sx == 0 && sy == 0) {
-		file->SetScriptInfo("PlayResX", std::to_string(vx));
-		file->SetScriptInfo("PlayResY", std::to_string(vy));
+		file->SetScriptInfo("PlayResX", TO_STRING(vx));
+		file->SetScriptInfo("PlayResY", TO_STRING(vy));
 		return true;
 	}
 
@@ -126,8 +133,8 @@
 		return commit_subs;
 
 	case MISMATCH_SET:
-		file->SetScriptInfo("PlayResX", std::to_string(vx));
-		file->SetScriptInfo("PlayResY", std::to_string(vy));
+		file->SetScriptInfo("PlayResX", TO_STRING(vx));
+		file->SetScriptInfo("PlayResY", TO_STRING(vy));
 		return true;
 
 	case MISMATCH_RESAMPLE:
