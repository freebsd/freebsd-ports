--- uhidd/lex.l~
+++ uhidd/lex.l
@@ -34,7 +34,6 @@
 
 #include "y.tab.h"
 
-#define YY_NO_UNPUT
 int lineno = 1;
 
 int	yylex(void);
@@ -42,6 +41,8 @@
 %}
 
 %option noyywrap
+%option nounput
+%option noinput
 
 %%
 
