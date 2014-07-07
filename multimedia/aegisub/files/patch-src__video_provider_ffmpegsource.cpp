--- src/video_provider_ffmpegsource.cpp.orig
+++ src/video_provider_ffmpegsource.cpp
@@ -48,6 +48,13 @@
 #include <wx/choicdlg.h>
 #include <wx/msgdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace {
 std::string colormatrix_description(int cs, int cr) {
 	// Assuming TV for unspecified
@@ -222,7 +229,7 @@
 	for (int CurFrameNum = 0; CurFrameNum < VideoInfo->NumFrames; CurFrameNum++) {
 		const FFMS_FrameInfo *CurFrameData = FFMS_GetFrameInfo(FrameData, CurFrameNum);
 		if (!CurFrameData)
-			throw VideoOpenError("Couldn't get info about frame " + std::to_string(CurFrameNum));
+			throw VideoOpenError("Couldn't get info about frame " + TO_STRING(CurFrameNum));
 
 		// keyframe?
 		if (CurFrameData->KeyFrame)
