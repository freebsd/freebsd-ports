diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ setbrk.c.orig setbrk.c
--- setbrk.c.orig	Fri Jun  4 02:51:02 2004
+++ setbrk.c	Sat Jun 19 18:42:24 2004
@@ -9,9 +9,10 @@
 
 #include	"defs.h"
 
-setbrk(incr)
+BYTPTR	setbrk(incr)
+	INT		incr;
 {
-	REG BYTPTR	a=sbrk(incr);
+	REG BYTPTR	a=(BYTPTR) sbrk(incr);
 	brkend=a+incr;
 	return(a);
 }
