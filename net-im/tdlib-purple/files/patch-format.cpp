--- format.cpp	2021-12-17 04:50:38.000000000 -0500
+++ format.cpp	2023-12-18 01:10:41.084981000 -0500
@@ -1,4 +1,4 @@
 #include "format.h"
-#include <fmt/format.h>
+#include <fmt/args.h>
 
 std::string formatMessage(const char *fmt, std::initializer_list<std::string> args)
