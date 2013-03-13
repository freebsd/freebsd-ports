Index: Source/WebCore/css/CSSGrammar.y
===================================================================
--- Source/WebCore/css/CSSGrammar.y	(revision 124098)
+++ Source/WebCore/css/CSSGrammar.y	(revision 124099)
@@ -54,11 +54,10 @@
 #define YYDEBUG 0

-// FIXME: Replace with %parse-param { CSSParser* parser } once we can depend on bison 2.x
-#define YYPARSE_PARAM parser
-#define YYLEX_PARAM parser
-
 %}

 %pure_parser
+
+%parse-param { CSSParser* parser }
+%lex-param { CSSParser* parser }

 %union {
@@ -90,5 +89,5 @@
 %{

-static inline int cssyyerror(const char*)
+static inline int cssyyerror(void*, const char*)
 {
     return 1;
