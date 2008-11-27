--- ospfctl/parser.c.orig	2008-02-07 19:13:50.000000000 +0300
+++ ospfctl/parser.c	2008-02-07 19:15:47.000000000 +0300
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
