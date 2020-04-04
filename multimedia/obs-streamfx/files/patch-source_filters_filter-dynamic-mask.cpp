--- source/filters/filter-dynamic-mask.cpp.orig	2020-04-04 05:10:52 UTC
+++ source/filters/filter-dynamic-mask.cpp
@@ -20,6 +20,7 @@
 #include "filter-dynamic-mask.hpp"
 #include <sstream>
 #include <stdexcept>
+#include <vector>
 #include "strings.hpp"
 
 // Filter to allow dynamic masking
