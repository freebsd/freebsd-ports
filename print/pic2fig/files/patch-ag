--- picl.c.orig	Wed Apr  3 10:27:34 2002
+++ picl.c	Wed Apr  3 10:29:53 2002
@@ -17,7 +17,7 @@
 int yymorfg;
 extern char *yysptr, yysbuf[];
 int yytchar;
-FILE *yyin = {stdin}, *yyout = {stdout};
+FILE *yyin, *yyout;
 extern int yylineno;
 struct yysvf { 
 	struct yywork *yystoff;
@@ -40,7 +40,6 @@
 #include "pic.h"
 # include "picy.h"
 
-extern	float	atof();
 extern	char	*filename;
 extern	int	synerr;
 
