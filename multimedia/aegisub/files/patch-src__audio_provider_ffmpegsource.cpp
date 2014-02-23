--- src/video_provider_ffmpegsource.cpp.orig
+++ src/video_provider_ffmpegsource.cpp
@@ -230,7 +230,8 @@
 	Width	= TempFrame->EncodedWidth;
 	Height	= TempFrame->EncodedHeight;
 
-	if (FFMS_SetOutputFormatV(VideoSource, 1 << FFMS_GetPixFmt("bgra"), Width, Height, FFMS_RESIZER_BICUBIC, &ErrInfo)) {
+	const int TargetFormat[] = { FFMS_GetPixFmt("bgra"), -1 };
+	if (FFMS_SetOutputFormatV2(VideoSource, TargetFormat, Width, Height, FFMS_RESIZER_BICUBIC, &ErrInfo)) {
 		ErrorMsg.Append(wxString::Format(_T("Failed to set output format: %s"), ErrInfo.Buffer));
 		throw ErrorMsg;
 	}
