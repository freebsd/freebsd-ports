--- getoption.y.orig	2014-07-06 11:40:52.000000000 +0200
+++ getoption.y	2014-07-06 11:40:40.000000000 +0200
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
