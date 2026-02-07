diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ error.c.orig error.c
--- error.c.orig	Fri Jun  4 02:51:01 2004
+++ error.c	Sat Jun 19 18:42:22 2004
@@ -9,15 +9,17 @@
 
 #include	"defs.h"
 
+STRING		exitadr;
+INT		exitval;
 
 /* ========	error handling	======== */
 
-exitset()
+VOID	exitset()
 {
 	assnum(&exitadr,exitval);
 }
 
-sigchk()
+VOID	sigchk()
 {
 	/* Find out if it is time to go away.
 	 * `trapnote' is set to SIGSET when fault is seen and
@@ -25,26 +27,29 @@
 	 */
 	IF trapnote&SIGSET
 	THEN	exitsh(SIGFAIL);
+		/*NOTREACHED*/
 	FI
 }
 
-failed(s1,s2)
-	STRING	s1, s2;
+VOID	failed(s1,s2)
+	CSTRING	s1, s2;
 {
 	prp(); prs(s1); 
 	IF s2
 	THEN	prs(colon); prs(s2);
 	FI
 	newline(); exitsh(ERROR);
+	/*NOTREACHED*/
 }
 
-error(s)
-	STRING	s;
+VOID	error(s)
+	CSTRING	s;
 {
 	failed(s,NIL);
+	/*NOTREACHED*/
 }
 
-exitsh(xno)
+VOID	exitsh(xno)
 	INT	xno;
 {
 	/* Arrive here from `FATAL' errors
@@ -57,23 +62,29 @@
 	exitval=xno;
 	IF (flags & (forked|errflg|ttyflg)) != ttyflg
 	THEN	done();
+		/*NOTREACHED*/
 	ELSE	clearup();
+#if defined(SYSIII)
+		execbrk = breakcnt = 0;
+#endif
 		longjmp(errshell,1);
 	FI
 }
 
-done()
+VOID	done()
 {
 	REG STRING	t;
-	IF t=trapcom[0]
+
+	IF (t=trapcom[0])!=NIL			/* GCC */
 	THEN	trapcom[0]=0; /*should free but not long */
 		execexp(t,0);
 	FI
 	rmtemp(0);
 	exit(exitval);
+	/*NOTREACHED*/
 }
 
-rmtemp(base)
+VOID	rmtemp(base)
 	IOPTR		base;
 {
 	WHILE iotemp>base
