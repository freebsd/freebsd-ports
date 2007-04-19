--- moo.y.orig	Thu Apr  5 14:14:22 2007
+++ moo.y	Thu Apr  5 14:14:29 2007
@@ -37,7 +37,7 @@
 
 static void		divbyzero(void);
 static void		printnum(int64_t);
-__dead static void	usage(void);
+__dead2 static void	usage(void);
 void			yyerror(char *);
 int			yylex(void);
 int			yyparse(void);
