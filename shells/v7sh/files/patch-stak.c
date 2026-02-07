diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ stak.c.orig stak.c
--- stak.c.orig	Fri Jun  4 02:51:02 2004
+++ stak.c	Sat Jun 19 18:42:24 2004
@@ -9,17 +9,19 @@
 
 #include	"defs.h"
 
-STKPTR		stakbot=nullstr;
-
-
+BLKPTR		stakbsy;
+STKPTR		stakbas;
+STKPTR		brkend;
+STKPTR		stakbot=(STKPTR) nullstr;
+STKPTR		staktop;
 
 /* ========	storage allocation	======== */
 
 STKPTR	getstak(asize)
-	INT		asize;
+	POS		asize;
 {	/* allocate requested stack */
 	REG STKPTR	oldstak;
-	REG INT		size;
+	REG POS		size;
 
 	size=round(asize,BYTESPERWORD);
 	oldstak=stakbot;
@@ -51,7 +53,7 @@
 {	/* tidy up after `locstak' */
 	REG STKPTR	oldstak;
 	*argp++=0;
-	oldstak=stakbot; stakbot=staktop=round(argp,BYTESPERWORD);
+	oldstak=stakbot; stakbot=staktop=(STKPTR) round(argp,BYTESPERWORD);
 	return(oldstak);
 }
 
@@ -59,15 +61,15 @@
 	REG STKPTR 	x;
 {
 	/* try to bring stack back to x */
-	WHILE ADR(stakbsy)>ADR(x)
+	WHILE ADR((STKPTR) stakbsy)>ADR(x)
 	DO free(stakbsy);
 	   stakbsy = stakbsy->word;
 	OD
 	staktop=stakbot=max(ADR(x),ADR(stakbas));
-	rmtemp(x);
+	rmtemp((IOPTR) x);
 }
 
-stakchk()
+VOID	stakchk()
 {
 	IF (brkend-stakbas)>BRKINCR+BRKINCR
 	THEN	setbrk(-BRKINCR);
@@ -75,7 +77,7 @@
 }
 
 STKPTR	cpystak(x)
-	STKPTR		x;
+	CSTKPTR		x;
 {
 	return(endstak(movstr(x,locstak())));
 }
