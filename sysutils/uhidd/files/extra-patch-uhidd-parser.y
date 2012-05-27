--- uhidd/parser.y~
+++ uhidd/parser.y
@@ -32,13 +32,13 @@
 #include <err.h>
 #include <errno.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
 
 #include "uhidd.h"
 
 extern int yylex(void);
-extern int yyparse(void);
 extern int lineno;
 extern FILE *yyin;

