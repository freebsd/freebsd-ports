--- nasl/nasl_grammar.y.orig	2009-02-10 11:14:10 UTC
+++ nasl/nasl_grammar.y
@@ -1,4 +1,6 @@
 %pure_parser
+%parse-param {void *parm}
+%lex-param {void *parm}
 %expect 1
 %{
 /* Nessus Attack Scripting Language version 2
@@ -19,9 +21,6 @@
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#define YYPARSE_PARAM parm
-#define YYLEX_PARAM parm
-
 #define LNB	(((naslctxt*)parm)->line_nb)
 #include "includes.h"
 #include "nasl_tree.h"
@@ -32,7 +31,7 @@
 #include "nasl_debug.h"
 #include "nasl_signature.h"
 
-static void naslerror(const char *);
+static void naslerror(naslctxt *, const char *);
 #define YYERROR_VERBOSE
 %}
 
@@ -470,7 +469,7 @@ glob: GLOBAL arg_decl 
 #include <stdlib.h>
 
 static void 
-naslerror(const char *s)
+naslerror(naslctxt *parm, const char *s)
 {
   fputs(s, stderr);
 }
