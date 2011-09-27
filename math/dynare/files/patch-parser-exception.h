--- dynare++/parser/cc/parser_exception.h.orig	2011-08-21 19:10:51.000000000 +0200
+++ dynare++/parser/cc/parser_exception.h	2011-08-21 19:31:06.000000000 +0200
@@ -6,6 +6,7 @@
 #define OG_FORMULA_PARSER_H
 
 #include <string>
+#include <stdio.h>
 
 namespace ogp {
 	using std::string;
