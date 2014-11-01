--- gst/parse/grammar.y.orig	2011-12-30 01:14:35 UTC
+++ gst/parse/grammar.y
@@ -26,7 +26,6 @@
  */
 
 #define YYERROR_VERBOSE 1
-#define YYLEX_PARAM scanner
 
 #define YYENABLE_NLS 0
 
@@ -648,6 +647,7 @@ static int yyerror (void *scanner, graph
 %right '.'
 %left '!' '='
 
+%lex-param { void *scanner }
 %parse-param { void *scanner }
 %parse-param { graph_t *graph }
 %pure-parser
