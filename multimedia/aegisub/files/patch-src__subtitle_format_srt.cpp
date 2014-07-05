--- src/subtitle_format_srt.cpp.orig
+++ src/subtitle_format_srt.cpp
@@ -54,6 +54,13 @@
 #include <boost/regex.hpp>
 #include <map>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 DEFINE_SIMPLE_EXCEPTION(SRTParseError, SubtitleFormatParseError, "subtitle_io/parse/srt")
 
 namespace {
@@ -481,7 +488,7 @@
 	// Write lines
 	int i=0;
 	for (auto current : copy.Line | agi::of_type<AssDialogue>()) {
-		file.WriteLineToFile(std::to_string(++i));
+		file.WriteLineToFile(TO_STRING(++i));
 		file.WriteLineToFile(WriteSRTTime(current->Start) + " --> " + WriteSRTTime(current->End));
 		file.WriteLineToFile(ConvertTags(current));
 		file.WriteLineToFile("");
