--- libaegisub/common/charset.cpp.orig	2014-08-05 20:44:44.000000000 +0900
+++ libaegisub/common/charset.cpp	2014-08-05 20:44:59.000000000 +0900
@@ -20,6 +20,7 @@
 
 #include "libaegisub/file_mapping.h"
 
+#include <algorithm>
 #include <string>
 
 #ifndef _WIN32
