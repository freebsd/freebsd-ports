--- src/tokenize.cpp.orig	2021-05-13 14:53:40 UTC
+++ src/tokenize.cpp
@@ -16,10 +16,7 @@
 #include "unc_ctype.h"
 
 #include <regex>
-
-#ifdef WIN32
-#include <stack>            // to get std::stack
-#endif // WIN32
+#include <stack>
 
 
 #define LE_COUNT(x)    cpd.le_counts[static_cast<size_t>(LE_ ## x)]
