--- src/output.cpp.orig	2021-05-13 14:53:40 UTC
+++ src/output.cpp
@@ -17,12 +17,9 @@
 #include "unc_ctype.h"
 #include "unicode.h"
 
+#include <map>
 #include <regex>
 #include <set>
-
-#ifdef WIN32
-#include <map>                    // to get std::map
-#endif // WIN32
 
 
 constexpr static auto LCURRENT = LOUTPUT;
