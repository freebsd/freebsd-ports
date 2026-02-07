diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ macro.c.orig macro.c
--- macro.c.orig	Fri Jun  4 02:51:01 2004
+++ macro.c	Sat Jun 19 18:42:23 2004
@@ -10,27 +10,37 @@
 #include	"defs.h"
 #include	"sym.h"
 
-LOCAL CHAR	quote;	/* used locally */
-LOCAL CHAR	quoted;	/* used locally */
+LOCAL VOID	copyto(INT);
+LOCAL VOID	skipto(INT);
+LOCAL INT	getch(INT);
+LOCAL VOID	comsubst(VOID);
+#define flush	flush_
+LOCAL VOID	flush(INT);
 
+LOCAL INT	quote;	/* used locally */
+LOCAL BOOL	quoted;	/* used locally */
 
 
-LOCAL STRING	copyto(endch)
-	REG CHAR	endch;
+LOCAL VOID	copyto(endch)
+	REG INT		endch;
 {
-	REG CHAR	c;
+	REG INT		c;
 
 	WHILE (c=getch(endch))!=endch ANDF c
 	DO pushstak(c|quote) OD
 	zerostak();
-	IF c!=endch THEN error(badsub) FI
+	IF c!=endch
+	THEN	error(badsub);
+		/*NOTREACHED*/
+	FI
 }
 
-LOCAL	skipto(endch)
-	REG CHAR	endch;
+LOCAL VOID	skipto(endch)
+	REG INT		endch;
 {
 	/* skip chars up to } */
-	REG CHAR	c;
+	REG INT		c;
+
 	WHILE (c=readc()) ANDF c!=endch
 	DO	SWITCH c IN
 
@@ -43,13 +53,16 @@
 				FI
 		ENDSW
 	OD
-	IF c!=endch THEN error(badsub) FI
+	IF c!=endch
+	THEN	error(badsub);
+		/*NOTREACHED*/
+	FI
 }
 
-LOCAL	getch(endch)
+LOCAL INT	getch(endch)
 	CHAR		endch;
 {
-	REG CHAR	d;
+	REG INT		d;
 
 retry:
 	d=readc();
@@ -62,13 +75,16 @@
 		THEN	NAMPTR		n=NIL;
 			INT		dolg=0;
 			BOOL		bra;
-			REG STRING	argp, v;
+			REG STRING	argp, v=NIL;	/* GCC */
+#if defined(SYSIII)
+			BOOL		nulflg;
+#endif
 			CHAR		idb[2];
 			STRING		id=idb;
 
-			IF bra=(c==BRACE) THEN c=readc() FI
+			IF (bra=c==BRACE)!=0 THEN c=readc() FI	/* GCC */
 			IF letter(c)
-			THEN	argp=relstak();
+			THEN	argp=(STRING) relstak();
 				WHILE alphanum(c) DO pushstak(c); c=readc() OD
 				zerostak();
 				n=lookup(absstak(argp)); setstak(argp);
@@ -80,7 +96,7 @@
 				THEN	dolg=1; c='1';
 				FI
 				c -= '0';
-				v=((c==0) ? cmdadr : (c<=dolc) ? dolv[c] : (dolg=0));
+				v=((c==0) ? cmdadr : (c<=dolc) ? dolv[c] : (STRING) (dolg=0));
 			ELIF c=='$'
 			THEN	v=pidadr;
 			ELIF c=='!'
@@ -91,18 +107,31 @@
 			THEN	v=exitadr;
 			ELIF c=='-'
 			THEN	v=flagadr;
-			ELIF bra THEN error(badsub);
+			ELIF bra
+			THEN	error(badsub);
+				/*NOTREACHED*/
 			ELSE	goto retry;
 			FI
 			c = readc();
+#if defined(SYSIII)
+			IF c==':' ANDF bra	/* null and unset fix */
+			THEN	nulflg=1; c=readc();
+			ELSE	nulflg=0;
+			FI
+#endif
 			IF !defchar(c) ANDF bra
 			THEN	error(badsub);
+				/*NOTREACHED*/
 			FI
 			argp=0;
 			IF bra
 			THEN	IF c!='}'
-				THEN	argp=relstak();
+				THEN	argp=(STRING) relstak();
+#if defined(SYSIII)
+					IF (v==0 ORF (nulflg ANDF *v==0)) NEQ (setchar(c))
+#else /* V7 */
 					IF (v==0)NEQ(setchar(c))
+#endif
 					THEN	copyto('}');
 					ELSE	skipto('}');
 					FI
@@ -110,9 +139,13 @@
 				FI
 			ELSE	peekc = c|MARK; c = 0;
 			FI
+#if defined(SYSIII)
+			IF v ANDF (!nulflg ORF *v)
+#else /* V7 */
 			IF v
+#endif
 			THEN	IF c!='+'
-				THEN	LOOP WHILE c = *v++
+				THEN	LOOP WHILE (c = *v++)!=0 /* GCC */
 					     DO pushstak(c|quote); OD
 					     IF dolg==0 ORF (++dolg>dolc)
 					     THEN break;
@@ -123,14 +156,21 @@
 			ELIF argp
 			THEN	IF c=='?'
 				THEN	failed(id,*argp?argp:badparam);
+					/*NOTREACHED*/
 				ELIF c=='='
 				THEN	IF n
 					THEN	assign(n,argp);
 					ELSE	error(badsub);
+						/*NOTREACHED*/
 					FI
 				FI
 			ELIF flags&setflg
+#if defined(SYSIII)
+			THEN	failed(id,unset);
+#else /* V7 */
 			THEN	failed(id,badparam);
+#endif
+				/*NOTREACHED*/
 			FI
 			goto retry;
 		ELSE	peekc=c|MARK;
@@ -152,24 +192,25 @@
 	 * Leaves result on top of stack
 	 */
 	REG BOOL	savqu =quoted;
-	REG CHAR	savq = quote;
+	REG INT		savq = quote;
 	FILEHDR		fb;
 
-	push(&fb); estabf(as);
+	push((FILEPTR) &fb); estabf(as);
 	usestak();
 	quote=0; quoted=0;
 	copyto(0);
 	pop();
 	IF quoted ANDF (stakbot==staktop) THEN pushstak(QUOTE) FI
+	/* above is the fix for *'.c' bug */
 	quote=savq; quoted=savqu;
 	return(fixstak());
 }
 
-LOCAL	comsubst()
+LOCAL VOID	comsubst()
 {
 	/* command substn */
 	FILEBLK		cb;
-	REG CHAR	d;
+	REG INT		d;
 	REG STKPTR	savptr = fixstak();
 
 	usestak();
@@ -194,8 +235,16 @@
 	   close(pv[OTPIPE]);
 	END
 	tdystak(savptr); staktop=movstr(savptr,stakbot);
-	WHILE d=readc() DO pushstak(d|quote) OD
+#if defined(RENO)
+	WHILE (d=readc())!=0 DO locstak(); pushstak(d|quote) OD
+#else /* V7 */
+	WHILE (d=readc())!=0 DO pushstak(d|quote) OD	/* GCC */
+#endif
+#if defined(SYSIII)
+	await(0,0);
+#else /* V7 */
 	await(0);
+#endif
 	WHILE stakbot!=staktop
 	DO	IF (*--staktop&STRIP)!=NL
 		THEN	++staktop; break;
@@ -206,16 +255,16 @@
 
 #define CPYSIZ	512
 
-subst(in,ot)
+VOID	subst(in,ot)
 	INT		in, ot;
 {
-	REG CHAR	c;
+	REG INT		c;
 	FILEBLK		fb;
 	REG INT		count=CPYSIZ;
 
 	push(&fb); initf(in);
 	/* DQUOTE used to stop it from quoting */
-	WHILE c=(getch(DQUOTE)&STRIP)
+	WHILE (c=(getch(DQUOTE)&STRIP))!=0		/* GCC */
 	DO pushstak(c);
 	   IF --count == 0
 	   THEN	flush(ot); count=CPYSIZ;
@@ -225,9 +274,10 @@
 	pop();
 }
 
-LOCAL	flush(ot)
+LOCAL VOID	flush(ot)
+	INT		ot;
 {
-	write(ot,stakbot,staktop-stakbot);
-	IF flags&execpr THEN write(output,stakbot,staktop-stakbot) FI
+	write(ot,stakbot,(SIZE) (staktop-stakbot));
+	IF flags&execpr THEN write(output,stakbot,(SIZE) (staktop-stakbot)) FI
 	staktop=stakbot;
 }
