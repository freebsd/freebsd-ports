--- ginsh/ginsh_lexer.ll.orig	Tue Oct 15 17:19:57 2002
+++ ginsh/ginsh_lexer.ll	Tue Oct 15 17:20:27 2002
@@ -32,6 +32,8 @@
 #include "ginsh.h"
 #include "ginsh_parser.h"
 
+extern YYSTYPE yylval;
+
 #define YY_INPUT(buf, result, max_size) (result = ginsh_input(buf, max_size))
 
 // Table of all used symbols
