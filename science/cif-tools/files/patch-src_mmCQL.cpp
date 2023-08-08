--- src/mmCQL.cpp.orig	2022-10-04 01:58:30 UTC
+++ src/mmCQL.cpp
@@ -29,6 +29,7 @@
 #include <fstream>
 #include <filesystem>
 #include <functional>
+#include <stack>
 #include <unordered_set>
 
 #include <boost/program_options.hpp>
