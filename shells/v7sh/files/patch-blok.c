diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ blok.c.orig blok.c
--- blok.c.orig	Fri Jun  4 02:51:00 2004
+++ blok.c	Sat Jun 19 18:42:21 2004
@@ -18,9 +18,9 @@
 #define BUSY 01
 #define busy(x)	(Rcheat((x)->word)&BUSY)
 
-POS		brkincr=BRKINCR;
-BLKPTR		blokp;			/*current search pointer*/
-BLKPTR		bloktop=BLK(end);	/*top of arena (last blok)*/
+INT		brkincr=BRKINCR;
+LOCAL BLKPTR	blokp;			/*current search pointer*/
+LOCAL BLKPTR	bloktop=BLK(end);	/*top of arena (last blok)*/
 
 
 
@@ -34,13 +34,13 @@
 		REG BLKPTR	q;
 		REP	IF !busy(p)
 			THEN	WHILE !busy(q = p->word) DO p->word = q->word OD
-				IF ADR(q)-ADR(p) >= rbytes
+				IF (POS) (ADR(q)-ADR(p)) >= rbytes
 				THEN	blokp = BLK(ADR(p)+rbytes);
 					IF q > blokp
 					THEN	blokp->word = p->word;
 					FI
 					p->word=BLK(Rcheat(blokp)|BUSY);
-					return(ADR(p+1));
+					return((ADDRESS) ADR(p+1));
 				FI
 			FI
 			q = p; p = BLK(Rcheat(p->word)&~BUSY);
@@ -57,7 +57,7 @@
 		REG BLKPTR	blokstak;
 
 		pushstak(0);
-		rndstak=round(staktop,BYTESPERWORD);
+		rndstak=(STKPTR) round(staktop,BYTESPERWORD);
 		blokstak=BLK(stakbas)-1;
 		blokstak->word=stakbsy; stakbsy=blokstak;
 		bloktop->word=BLK(Rcheat(rndstak)|BUSY);
