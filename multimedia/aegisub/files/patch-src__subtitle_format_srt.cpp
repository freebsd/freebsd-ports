--- src/subtitle_format_srt.cpp.orig	2014-07-28 23:29:16.000000000 +0900
+++ src/subtitle_format_srt.cpp	2014-08-05 08:01:33.000000000 +0900
@@ -50,6 +50,13 @@
 #include <boost/algorithm/string/trim.hpp>
 #include <boost/regex.hpp>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 DEFINE_EXCEPTION(SRTParseError, SubtitleFormatParseError);
 
 namespace {
@@ -435,7 +442,7 @@
 	// Write lines
 	int i=0;
 	for (auto const& current : copy.Events) {
-		file.WriteLineToFile(std::to_string(++i));
+		file.WriteLineToFile(TO_STRING(++i));
 		file.WriteLineToFile(WriteSRTTime(current.Start) + " --> " + WriteSRTTime(current.End));
 		file.WriteLineToFile(ConvertTags(&current));
 		file.WriteLineToFile("");
