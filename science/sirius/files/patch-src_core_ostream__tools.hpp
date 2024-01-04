- workaround for https://github.com/electronic-structure/SIRIUS/issues/946

--- src/core/ostream_tools.hpp.orig	2024-01-04 03:41:15 UTC
+++ src/core/ostream_tools.hpp
@@ -29,6 +29,7 @@
 #include <iomanip>
 #include <vector>
 #include <cmath>
+#include <sstream>
 
 namespace sirius {
 
