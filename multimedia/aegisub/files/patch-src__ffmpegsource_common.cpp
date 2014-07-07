--- src/ffmpegsource_common.cpp.orig
+++ src/ffmpegsource_common.cpp
@@ -56,6 +56,13 @@
 #include <wx/config.h>
 #include <wx/choicdlg.h> // Keep this last so wxUSE_CHOICEDLG is set.
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 #ifdef _WIN32
 #include <objbase.h>
 
@@ -221,7 +228,7 @@
 	hash.process_bytes(filename.string().c_str(), filename.string().size());
 
 	// Generate the filename
-	auto result = config::path->Decode("?local/ffms2cache/" + std::to_string(hash.checksum()) + "_" + std::to_string(len) + "_" + std::to_string(agi::fs::ModifiedTime(filename)) + ".ffindex");
+	auto result = config::path->Decode("?local/ffms2cache/" + TO_STRING(hash.checksum()) + "_" + TO_STRING(len) + "_" + TO_STRING(agi::fs::ModifiedTime(filename)) + ".ffindex");
 
 	// Ensure that folder exists
 	agi::fs::CreateDirectory(result.parent_path());
