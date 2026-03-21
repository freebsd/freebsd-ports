--- lttoolbox/ustring.h.orig	2025-03-06 14:48:10 UTC
+++ lttoolbox/ustring.h
@@ -25,7 +25,7 @@
 #include <utf8.h>
 #include <vector>
 #include <cstdint>
-#include <iomanip>
+#include <iostream>
 
 typedef std::basic_string<UChar> UString;
 typedef std::basic_string_view<UChar> UStringView;
