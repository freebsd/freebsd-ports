--- uhidd/parser.y.old	2012-10-14 22:33:00.000000000 +0200
+++ uhidd/parser.y	2012-10-14 22:33:06.000000000 +0200
@@ -39,7 +39,6 @@
 #include "uhidd.h"
 
 extern int yylex(void);
-extern int yyparse(void);
 extern int lineno;
 extern FILE *yyin;
 
