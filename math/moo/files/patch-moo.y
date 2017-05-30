--- moo.y.orig	2016-06-04 10:05:27 UTC
+++ moo.y
@@ -34,7 +34,7 @@ static int used_oct;
 
 static void		divbyzero(void);
 static void		printnum(int64_t);
-__dead static void	usage(void);
+__dead2 static void	usage(void);
 void			yyerror(char *);
 int			yylex(void);
 int			yyparse(void);
@@ -317,9 +317,6 @@ main(int argc, char *argv[])
 {
 	int ch;
 
-	if (pledge("stdio tmppath", NULL) == -1)
-		err(1, "pledge");
-
 	while ((ch = getopt(argc, argv, "0123456789b:lsuw:")) != -1)
 		switch (ch) {
 		/*
@@ -403,9 +400,6 @@ DONEPARSING:
 		yyin = sfp;
 	}
 
-	if (pledge("stdio", NULL) == -1)
-		err(1, "pledge");
-
 	yyparse();
 
 	return (0);
