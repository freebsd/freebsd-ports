diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ word.c.orig word.c
--- word.c.orig	Fri Jun  4 02:51:02 2004
+++ word.c	Sat Jun 19 18:42:25 2004
@@ -10,19 +10,51 @@
 #include	"defs.h"
 #include	"sym.h"
 
+LOCAL INT	readb(VOID);
+
+INT		wdval;
+INT		wdnum;
+ARGPTR		wdarg;
+INT		wdset;
+BOOL		reserv;
+INT		peekc;
+BOOL		rwait;
+
 
 /* ========	character handling for command lines	========*/
 
 
-word()
+INT	word()
 {
-	REG CHAR	c, d;
-	REG CHAR	*argp=locstak()+BYTESPERWORD;
+	REG INT		c, d;
+	REG STRING	argp=(STRING) (locstak()+BYTESPERWORD);
+	REG ARGPTR	ap;
 	INT		alpha=1;
 
 	wdnum=0; wdset=0;
 
+#if defined(SYSIII)
+	LOOP
+#endif
 	WHILE (c=nextc(0), space(c)) DONE
+#if defined(RENO)
+		IF c==COMCHAR ANDF ((flags&prompt)==0 ORF ((flags&ttyflg) ANDF
+		   standin->fstak!=0))
+		THEN	WHILE (c=readc())!=EOF ANDF c!=NL DONE
+#if defined(SYSIII)
+			peekc=c;
+		ELSE	break;	/* out of comment - white space loop */
+#endif
+		FI
+#endif
+#if defined(SYSIII)
+		IF c==COMCHAR
+		THEN	WHILE (c=readc())!=EOF ANDF c!=NL DONE
+			peekc=c;
+		ELSE	break;	/* out of comment - white space loop */
+		FI
+	POOL
+#endif
 	IF !eofmeta(c)
 	THEN	REP	IF c==LITERAL
 			THEN	*argp++=(DQUOTE);
@@ -39,21 +71,29 @@
 				FI
 			FI
 		PER (c=nextc(0), !eofmeta(c)) DONE
-		argp=endstak(argp);
-		IF !letter(argp->argval[0]) THEN wdset=0 FI
+		ap=(ARGPTR) endstak(argp);
+		IF !letter((INT) ap->argval[0]) THEN wdset=0 FI
 
 		peekc=c|MARK;
-		IF argp->argval[1]==0 ANDF (d=argp->argval[0], digit(d)) ANDF (c=='>' ORF c=='<')
+		IF ap->argval[1]==0 ANDF (d=ap->argval[0], digit(d)) ANDF (c=='>' ORF c=='<')
 		THEN	word(); wdnum=d-'0';
 		ELSE	/*check for reserved words*/
-			IF reserv==FALSE ORF (wdval=syslook(argp->argval,reserved))==0
-			THEN	wdarg=argp; wdval=0;
+			IF reserv==FALSE ORF (wdval=syslook(ap->argval,reserved))==0
+			THEN	wdarg=ap; wdval=0;
 			FI
 		FI
 
 	ELIF dipchar(c)
 	THEN	IF (d=nextc(0))==c
 		THEN	wdval = c|SYMREP;
+#if defined(SYSIII)
+			IF c=='<'
+			THEN	IF (d=nextc(0))=='-'
+				THEN	stripflg++;
+				ELSE	peekc = d|MARK;
+				FI
+			FI
+#endif
 		ELSE	peekc = d|MARK; wdval = c;
 		FI
 	ELSE	IF (wdval=c)==EOF
@@ -67,10 +107,10 @@
 	return(wdval);
 }
 
-nextc(quote)
-	CHAR		quote;
+INT	nextc(quote)
+	INT		quote;
 {
-	REG CHAR	c, d;
+	REG INT		c, d;
 	IF (d=readc())==ESCAPE
 	THEN	IF (c=readc())==NL
 		THEN	chkpr(NL); d=nextc(quote);
@@ -82,15 +122,15 @@
 	return(d);
 }
 
-readc()
+INT	readc()
 {
-	REG CHAR	c;
+	REG INT		c;
 	REG INT		len;
-	REG FILE	f;
+	REG FILEPTR	f;
 
 retry:
 	IF peekc
-	THEN	c=peekc; peekc=0;
+	THEN	c=peekc&STRIP; peekc=0;
 	ELIF (f=standin, f->fnxt!=f->fend)
 	THEN	IF (c = *f->fnxt++)==0
 		THEN	IF f->feval
@@ -113,12 +153,26 @@
 	return(c);
 }
 
-LOCAL	readb()
+LOCAL INT	readb()
 {
-	REG FILE	f=standin;
+	REG FILEPTR	f=standin;
 	REG INT		len;
 
+#if defined(RENO)
+	IF setjmp(INTbuf) == 0 THEN trapjmp[INTR] = 1; FI
+#endif
+#if defined(SYSIII)
+	REP	IF trapnote&SIGSET
+		THEN	newline(); sigchk();
+		ELIF (trapnote&TRAPSET) ANDF (rwait>0)
+		THEN	newline(); chktrap(); clearup();
+		FI
+#else /* V7 */
 	REP	IF trapnote&SIGSET THEN newline(); sigchk() FI
-	PER (len=read(f->fdes,f->fbuf,f->fsiz))<0 ANDF trapnote DONE
+#endif
+	PER (len=read(f->fdes,f->fbuf,(SIZE) f->fsiz))<0 ANDF trapnote DONE
+#if defined(RENO)
+	trapjmp[INTR] = 0;
+#endif
 	return(len);
 }
