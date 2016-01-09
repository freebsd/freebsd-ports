--- src/dimacsparser.cpp.orig	2015-08-26 23:32:30 UTC
+++ src/dimacsparser.cpp
@@ -126,7 +126,7 @@ void DimacsParser::readClause(StreamBuff
     for (;;) {
         parsed_lit = parseInt(in);
         if (parsed_lit == 0) break;
-        var = abs(parsed_lit)-1;
+        var = std::abs(parsed_lit)-1;
         if (var >= (1ULL<<28)) {
             std::cerr
             << "ERROR! "
