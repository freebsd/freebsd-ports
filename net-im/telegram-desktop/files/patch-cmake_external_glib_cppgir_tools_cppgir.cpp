--- cmake/external/glib/cppgir/tools/cppgir.cpp.orig	2023-06-15 00:49:41 UTC
+++ cmake/external/glib/cppgir/tools/cppgir.cpp
@@ -3,8 +3,8 @@
 #include "genns.hpp"
 #include "repository.hpp"
 
-#include <experimental/filesystem>
-namespace fs = std::experimental::filesystem;
+#include <filesystem>
+namespace fs = std::filesystem;
 
 #include <boost/algorithm/string/classification.hpp>
 #include <boost/algorithm/string/split.hpp>
