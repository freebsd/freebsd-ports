--- src/subtitle_format_ass.cpp.orig	2014-08-05 23:16:03.000000000 +0900
+++ src/subtitle_format_ass.cpp	2014-08-05 23:18:02.000000000 +0900
@@ -31,6 +31,13 @@
 #include <libaegisub/ass/uuencode.h>
 #include <libaegisub/fs.h>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 DEFINE_EXCEPTION(AssParseError, SubtitleFormatParseError);
 
 void AssSubtitleFormat::ReadFile(AssFile *target, agi::fs::path const& filename, agi::vfr::Framerate const& fps, std::string const& encoding) const {
@@ -119,7 +126,7 @@
 	template<typename Number>
 	void WriteIfNotZero(const char *key, Number n) {
 		if (n != Number{})
-			file.WriteLineToFile(key + std::to_string(n));
+			file.WriteLineToFile(key + TO_STRING(n));
 	}
 
 	void WriteExtradata(std::vector<ExtradataEntry> const& extradata) {
@@ -131,7 +138,7 @@
 		file.WriteLineToFile("[Aegisub Extradata]");
 		for (auto const& edi : extradata) {
 			std::string line = "Data: ";
-			line += std::to_string(edi.id);
+			line += TO_STRING(edi.id);
 			line += ",";
 			line += inline_string_encode(edi.key);
 			line += ",";
