--- getoption.y.orig	1996-06-04 13:17:35 UTC
+++ getoption.y
@@ -163,14 +163,11 @@ static	int	Ycmp(char * pattern, char * string)
 
 extern 	char	* yytext;	/* defined by flex */
 
-/* static	int	yywrap()
+static	int	yywrap()
 	{
 		return	1;
 	}
-*/
 
-#define	yywrap()	1
-
 static	void	yyerror(char * msg)
 {
 	char	ebuf[2048];
@@ -309,7 +306,7 @@ struct	config_struct *	getoption(char * r, char * s, c
 	struct	member_struct	* mm;
 	struct	config_struct	* gg;
 
-#ifdef	YYDEBUG
+#if	YYDEBUG
 	extern	int	yydebug;
 	yydebug	= 1;
 #endif
@@ -344,7 +341,7 @@ struct	config_struct *	getmember(char * name)
 {
 	struct	config_struct	* gg;
 
-#ifdef	YYDEBUG
+#if	YYDEBUG
 	extern	int	yydebug;
 	yydebug	= 1;
 #endif
@@ -443,7 +440,7 @@ char **	get_mailer(char * mailer)
 {
 	struct	mailer_struct	* mm;
 
-#ifdef	YYDEBUG
+#if	YYDEBUG
 	extern	int	yydebug;
 	yydebug	= 1;
 #endif
