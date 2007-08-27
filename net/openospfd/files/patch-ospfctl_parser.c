--- ospfctl/parser.c.orig	Fri Jul 27 15:11:46 2007
+++ ospfctl/parser.c	Fri Jul 27 15:12:01 2007
@@ -32,23 +32,6 @@
 
 #include "parser.h"
 
-enum token_type {
-	NOTOKEN,
-	ENDTOKEN,
-	KEYWORD,
-	ADDRESS,
-	FLAG,
-	PREFIX,
-	IFNAME
-};
-
-struct token {
-	enum token_type		 type;
-	const char		*keyword;
-	int			 value;
-	const struct token	*next;
-};
-
 static const struct token t_main[];
 static const struct token t_fib[];
 static const struct token t_show[];
