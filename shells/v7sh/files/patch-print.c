diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ print.c.orig print.c
--- print.c.orig	Fri Jun  4 02:51:02 2004
+++ print.c	Sat Jun 19 18:42:24 2004
@@ -9,20 +9,20 @@
 
 #include	"defs.h"
 
-CHAR		numbuf[6];
+CHAR		numbuf[12];
 
 
 /* printing and io conversion */
 
-newline()
+VOID	newline()
 {	prc(NL);
 }
 
-blank()
+VOID	blank()
 {	prc(SP);
 }
 
-prp()
+VOID	prp()
 {
 	IF (flags&prompt)==0 ANDF cmdadr
 	THEN	prs(cmdadr); prs(colon);
@@ -30,47 +30,49 @@
 }
 
 VOID	prs(as)
-	STRING		as;
+	CSTRING		as;
 {
-	REG STRING	s;
+	REG CSTRING	s;
 
-	IF s=as
-	THEN	write(output,s,length(s)-1);
+	IF (s=as)!=NIL				/* GCC */
+	THEN	write(output,s,(SIZE) length(s)-1);
 	FI
 }
 
 VOID	prc(c)
-	CHAR		c;
+	INT		c;
 {
 	IF c
-	THEN	write(output,&c,1);
+	THEN	write(output,&c,(SIZE) 1);
 	FI
 }
 
-prt(t)
-	L_INT		t;
+VOID	prt(t)
+	CLOCK		t;
 {
-	REG INT	hr, min, sec;
+	REG CLOCK	hr, min, sec;
 
 	t += 30; t /= 60;
 	sec=t%60; t /= 60;
 	min=t%60;
-	IF hr=t/60
-	THEN	prn(hr); prc('h');
+	IF (hr=t/60)!=0				/* GCC */
+	THEN	prl(hr); prc('h');
 	FI
-	prn(min); prc('m');
-	prn(sec); prc('s');
+	prl(min); prc('m');
+	prl(sec); prc('s');
 }
 
-prn(n)
+VOID	prn(n)
 	INT		n;
 {
 	itos(n); prs(numbuf);
 }
 
-itos(n)
+VOID	itos(n)
+	INT		n;
 {
-	REG char *abuf; REG POS a, i; INT pr, d;
+	REG STRING abuf; REG POS a, i; INT pr, d;
+
 	abuf=numbuf; pr=FALSE; a=n;
 	FOR i=10000; i!=1; i/=10
 	DO	IF (pr |= (d=a/i)) THEN *abuf++=d+'0' FI
@@ -80,18 +82,38 @@
 	*abuf++=0;
 }
 
-stoi(icp)
-STRING	icp;
+INT	stoi(icp)
+	CSTRING	icp;
 {
-	REG CHAR	*cp = icp;
+	REG CSTRING	cp = icp;
 	REG INT		r = 0;
-	REG CHAR	c;
+	REG INT		c;
 
 	WHILE (c = *cp, digit(c)) ANDF c ANDF r>=0
 	DO r = r*10 + c - '0'; cp++ OD
 	IF r<0 ORF cp==icp
 	THEN	failed(icp,badnum);
-	ELSE	return(r);
+		/*NOTREACHED*/
 	FI
+	return(r);
 }
 
+VOID	prl(n)	/* for ULIMIT */
+	LONG		n;
+{
+	ltos(n); prs(numbuf);
+}
+
+VOID	ltos(n)
+	LONG		n;
+{
+	REG STRING abuf; REG POS a, i; INT pr, d;
+
+	abuf=numbuf; pr=FALSE; a=n;
+	FOR i=1000000000; i!=1; i/=10
+	DO	IF (pr |= (d=(INT) (a/i))) THEN *abuf++=d+'0' FI
+		a %= i;
+	OD
+	*abuf++=a+'0';
+	*abuf++=0;
+}
