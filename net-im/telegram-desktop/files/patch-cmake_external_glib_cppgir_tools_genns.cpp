--- cmake/external/glib/cppgir/tools/genns.cpp.orig	2023-06-15 00:40:47 UTC
+++ cmake/external/glib/cppgir/tools/genns.cpp
@@ -5,8 +5,8 @@
 #include <boost/algorithm/string/join.hpp>
 #include <boost/format.hpp>
 
-#include <experimental/filesystem>
-namespace fs = std::experimental::filesystem;
+#include <filesystem>
+namespace fs = std::filesystem;
 
 #include <boost/property_tree/xml_parser.hpp>
 
