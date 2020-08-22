diff --git a/dtc-lexer.l b/dtc-lexer.l
index 5c6c3fd..b3b7270 100644
--- dtc-lexer.l
+++ dtc-lexer.l
@@ -23,7 +23,6 @@ LINECOMMENT	"//".*\n
 #include "srcpos.h"
 #include "dtc-parser.tab.h"
 
-YYLTYPE yylloc;
 extern bool treesource_error;
 
 /* CAUTION: this will stop working if we ever use yyless() or yyunput() */
