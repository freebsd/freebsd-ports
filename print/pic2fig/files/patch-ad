--- main.c.orig	Mon Feb  8 06:21:12 1988
+++ main.c	Wed Apr  3 10:28:56 2002
@@ -1,10 +1,10 @@
 #include	<stdio.h>
 #include	<ctype.h>
+#include	<strings.h>
 #include	"pic.h"
 #include	"picy.h"
 
 static reset();
-extern char *sprintf(), *strcpy();
 
 struct	obj	*objlist[MAXOBJ];	/* store the elements here */
 int	nobj	= 0;
@@ -27,7 +27,7 @@
 float	deltx	= 6;	/* max x value in output, for scaling */
 float	delty	= 6;	/* max y value in output, for scaling */
 int	dbg	= 0;
-extern	FILE	*yyin;	/* input file pointer */
+extern	FILE	*yyin, *yyout;	/* input and out file pointers */
 FILE	*TEXFILE;	/* Output file */
 int	lineno	= 0;
 char	*filename	= "-";
@@ -51,6 +51,7 @@
 {
 	char TEXfilename[BUFSIZ], buffer[BUFSIZ], *bp, *rindex();
 
+	yyin = stdin; yyout = stdout;
 	cmdname = argv[0];
 	while (argc > 1 && *argv[1] == '-') {
 		switch (argv[1][1]) {
