--- src/video_context.cpp.orig
+++ src/video_context.cpp
@@ -58,6 +58,13 @@
 
 #include <wx/msgdlg.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 VideoContext::VideoContext()
 : playback(this)
 , playAudioOnStep(OPT_GET("Audio/Plays When Stepping Video"))
@@ -135,8 +142,8 @@
 		// If the script resolution hasn't been set at all just force it to the
 		// video resolution
 		if (sx == 0 && sy == 0) {
-			context->ass->SetScriptInfo("PlayResX", std::to_string(vx));
-			context->ass->SetScriptInfo("PlayResY", std::to_string(vy));
+			context->ass->SetScriptInfo("PlayResX", TO_STRING(vx));
+			context->ass->SetScriptInfo("PlayResY", TO_STRING(vy));
 			commit_subs = true;
 		}
 		// If it has been set to something other than a multiple of the video
@@ -153,8 +160,8 @@
 					break;
 				// Fallthrough to case 2
 			case 2: // Always change script res
-				context->ass->SetScriptInfo("PlayResX", std::to_string(vx));
-				context->ass->SetScriptInfo("PlayResY", std::to_string(vy));
+				context->ass->SetScriptInfo("PlayResX", TO_STRING(vx));
+				context->ass->SetScriptInfo("PlayResY", TO_STRING(vy));
 				commit_subs = true;
 				break;
 			default: // Never change
@@ -248,16 +255,16 @@
 
 	std::string ar;
 	if (ar_type == AspectRatio::Custom)
-		ar = "c" + std::to_string(ar_value);
+		ar = "c" + TO_STRING(ar_value);
 	else
-		ar = std::to_string((int)ar_type);
+		ar = TO_STRING((int)ar_type);
 
 	context->ass->SetScriptInfo("Video File", config::path->MakeRelative(video_filename, "?script").generic_string());
 	auto matrix = video_provider->GetColorSpace();
 	if (!matrix.empty())
 		context->ass->SetScriptInfo("YCbCr Matrix", matrix);
 	context->ass->SaveUIState("Video Aspect Ratio", ar);
-	context->ass->SaveUIState("Video Position", std::to_string(frame_n));
+	context->ass->SaveUIState("Video Position", TO_STRING(frame_n));
 }
 
 void VideoContext::JumpToFrame(int n) {
