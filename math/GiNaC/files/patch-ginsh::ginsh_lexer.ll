--- ginsh/ginsh_lexer.ll.orig	Tue Mar  6 18:18:07 2001
+++ ginsh/ginsh_lexer.ll	Tue Mar  6 18:22:06 2001
@@ -32,6 +32,8 @@
 #include "ginsh.h"
 #include "ginsh_parser.h"
 
+extern YYSTYPE yylval;
+
 #define YY_INPUT(buf, result, max_size) (result = ginsh_input(buf, max_size))
 
 // Table of all used symbols
