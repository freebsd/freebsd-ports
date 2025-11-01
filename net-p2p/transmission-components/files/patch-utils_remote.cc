--- utils/remote.cc.orig	2025-10-15 08:53:57 UTC
+++ utils/remote.cc
@@ -8,6 +8,7 @@
 #include <cctype> /* isspace */
 #include <cinttypes> // PRId64
 #include <cerrno>
+#include <chrono>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
@@ -900,7 +901,7 @@ static char* format_date(char* buf, size_t buflen, tim
 
 static char* format_date(char* buf, size_t buflen, time_t now)
 {
-    *fmt::format_to_n(buf, buflen - 1, "{:%a %b %d %T %Y}", fmt::localtime(now)).out = '\0';
+    *fmt::format_to_n(buf, buflen - 1, "{:%a %b %d %T %Y}", *std::localtime(&now)).out = '\0';
     return buf;
 }
 
