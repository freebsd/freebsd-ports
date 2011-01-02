--- ./aliases_scan.l.orig	2010-10-04 21:03:33.000000000 +0200
+++ ./aliases_scan.l	2010-12-26 22:03:33.000000000 +0000
@@ -3,8 +3,6 @@
 #include <string.h>
 #include "aliases_parse.h"
 
-#define YY_NO_INPUT
-
 int yylex(void);
 %}
 
@@ -13,9 +11,9 @@ int yylex(void);
 
 %%
 
+^([[:blank:]]*(#.*)?\n)+	;/* ignore empty lines */
 [^:,#[:space:][:cntrl:]]+	{yylval.ident = strdup(yytext); return T_IDENT;}
 [:,\n]				return yytext[0];
-^([[:blank:]]*(#.*)?\n)+	;/* ignore empty lines */
 (\n?[[:blank:]]+|#.*)+		;/* ignore whitespace and continuation */
 \\\n				;/* ignore continuation.  not allowed in comments */
 .				return T_ERROR;
