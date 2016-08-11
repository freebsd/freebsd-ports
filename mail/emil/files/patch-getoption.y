--- getoption.y.orig	1996-06-04 13:17:35 UTC
+++ getoption.y
@@ -163,13 +163,10 @@ static	int	Ycmp(char * pattern, char * s
 
 extern 	char	* yytext;	/* defined by flex */
 
-/* static	int	yywrap()
+static	int	yywrap()
 	{
 		return	1;
 	}
-*/
-
-#define	yywrap()	1
 
 static	void	yyerror(char * msg)
 {
