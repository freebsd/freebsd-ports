diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ args.c.orig args.c
--- args.c.orig	Fri Jun  4 02:51:00 2004
+++ args.c	Sat Jun 19 18:42:21 2004
@@ -9,24 +9,24 @@
 
 #include	"defs.h"
 
-PROC STRING *copyargs();
+LOCAL DOLPTR	copyargs(STRING *, INT);
 LOCAL DOLPTR	dolh;
 
 CHAR	flagadr[10];
-
 CHAR	flagchar[] = {
-	'x',	'n',	'v',	't',	's',	'i',	'e',	'r',	'k',	'u',	0
+	'x',	'n',	'v',	't', STDFLG,	'i',	'e',	'r',	'k',	'u',	0
 };
 INT	flagval[]  = {
 	execpr,	noexec,	readpr,	oneflg,	stdflg,	intflg,	errflg,	rshflg,	keyflg,	setflg,	0
 };
+DOLPTR	argfor;
 
 /* ========	option handling	======== */
 
 
 INT	options(argc,argv)
-	STRING		*argv;
 	INT		argc;
+	STRING		*argv;
 {
 	REG STRING	cp;
 	REG STRING	*argp=argv;
@@ -34,21 +34,66 @@
 	STRING		flagp;
 
 	IF argc>1 ANDF *argp[1]=='-'
+#if defined(SYSIII)
+	THEN
+		IF argp[1][1] == '-'
+		THEN    /* if first argument is "--" then options are not
+			   to be changed        Fix for problems getting
+			   $1 starting with a "-"
+			*/
+			argp[1] = argp[0]; argc--;
+			return(argc);
+		FI
+		cp = argp[1];
+		IF cp[1] == '\0' THEN flags &= ~(execpr|readpr) FI
+		/* Step along 'flagchar[]' looking for matches.
+		   'sicr' are not legal with 'set' command.
+		*/
+#else /* V7 */
 	THEN	cp=argp[1];
 		flags &= ~(execpr|readpr);
+#endif
 		WHILE *++cp
 		DO	flagc=flagchar;
 
 			WHILE *flagc ANDF *flagc != *cp DO flagc++ OD
 			IF *cp == *flagc
+#if defined(SYSIII)
+			THEN	IF eq(argv[0], "set") ANDF any(*cp, "sicr")
+				THEN failed(argv[1], badopt);
+					/*NOTREACHED*/
+				ELSE flags |= flagval[flagc-flagchar];
+				FI
+#else /* V7 */
 			THEN	flags |= flagval[flagc-flagchar];
+#endif
 			ELIF *cp=='c' ANDF argc>2 ANDF comdiv==0
 			THEN	comdiv=argp[2];
 				argp[1]=argp[0]; argp++; argc--;
 			ELSE	failed(argv[1],badopt);
+				/*NOTREACHED*/
+			FI
+		OD
+		argp[1]=argp[0]; argc--;
+#if defined(SYSIII)
+	ELIF    argc >1 ANDF *argp[1]=='+' /* unset flags x, k, t, n, v, e, u */
+	THEN    cp = argp[1];
+		WHILE *++cp
+		DO
+			flagc = flagchar;
+			WHILE *flagc ANDF *flagc != *cp DO flagc++ OD
+				/*      step through flags      */
+			IF !any(*cp, "csir") ANDF *cp == *flagc
+			THEN
+				IF (flags&flagval[flagc-flagchar])
+				/*      only turn off if already on     */
+				THEN
+					flags &= ~(flagval[flagc-flagchar])
+				FI
 			FI
 		OD
 		argp[1]=argp[0]; argc--;
+#endif
 	FI
 
 	/* set up $- */
@@ -67,6 +112,7 @@
 
 VOID	setargs(argi)
 	STRING		argi[];
+	/*	sets up positional parameters	*/
 {
 	/* count args */
 	REG STRING	*argp=argi;
@@ -80,45 +126,46 @@
 	assnum(&dolladr,dolc=argn-1);
 }
 
-freeargs(blk)
+DOLPTR	freeargs(blk)
 	DOLPTR		blk;
 {
 	REG STRING	*argp;
 	REG DOLPTR	argr=0;
 	REG DOLPTR	argblk;
 
-	IF argblk=blk
+	IF (argblk=blk)!=NIL			/* GCC */
 	THEN	argr = argblk->dolnxt;
 		IF (--argblk->doluse)==0
-		THEN	FOR argp=argblk->dolarg; Rcheat(*argp)!=ENDARGS; argp++
-			DO free(*argp) OD
-			free(argblk);
+		THEN	FOR argp=(STRING *) argblk->dolarg; Rcheat(*argp)!=ENDARGS; argp++
+			DO free((BLKPTR) *argp) OD
+			free((BLKPTR) argblk);
 		FI
 	FI
 	return(argr);
 }
 
-LOCAL STRING *	copyargs(from, n)
+LOCAL DOLPTR	copyargs(from, n)
 	STRING		from[];
+	INT		n;
 {
-	REG STRING *	np=alloc(sizeof(STRING*)*n+3*BYTESPERWORD);
-	REG STRING *	fp=from;
-	REG STRING *	pp=np;
+	REG DOLPTR	dp=(DOLPTR) alloc(sizeof(STRING*)*n+3*BYTESPERWORD);
+	REG STRING	*np;
+	REG STRING	*fp=from;
 
-	np->doluse=1;	/* use count */
-	np=np->dolarg;
+	dp->doluse=1;	/* use count */
+	np=(STRING *) dp->dolarg;
 	dolv=np;
 
 	WHILE n--
 	DO *np++ = make(*fp++) OD
 	*np++ = ENDARGS;
-	return(pp);
+	return(dp);
 }
 
-clearup()
+VOID	clearup()
 {
 	/* force `for' $* lists to go away */
-	WHILE argfor=freeargs(argfor) DONE
+	WHILE (argfor=freeargs(argfor))!=NIL DONE	/* GCC */
 
 	/* clean up io files */
 	WHILE pop() DONE
