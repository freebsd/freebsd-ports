--- lib/gram.y.orig	2013-03-14 21:31:55.000000000 +0800
+++ lib/gram.y	2013-03-14 21:32:31.000000000 +0800
@@ -9,7 +9,8 @@
 
 %start doc
 %pure-parser
-
+%parse-param {void* parser}
+%lex-param {void* parser}
 
 %{
 
@@ -24,9 +25,6 @@
 
 void apply_seq_in_map( SyckParser *parser, SyckNode *n );
 
-#define YYPARSE_PARAM   parser
-#define YYLEX_PARAM     parser
-
 #define NULL_NODE(parser, node) \
         SyckNode *node = syck_new_str( "", scalar_plain ); \
         if ( ((SyckParser *)parser)->taguri_expansion == 1 ) \
