diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ test.c.orig test.c
--- test.c.orig	Wed Jun  9 01:32:25 2004
+++ test.c	Sat Jun 19 18:42:25 2004
@@ -3,24 +3,40 @@
  *      [ expression ]
  */
 
+#if defined(SYSIII)
 #include	"defs.h"
-#include <sys/types.h>
-#include <sys/stat.h>
-#define exp exp_
-
-INT	ap, ac;
-STRING	*av;
-
-test(argn, com)
-	STRING com[];
-	INT argn;
-{
 
+#undef eq
+#define eq(a,b)	((at=a)==0?0:cf(at,b)==0)
 
+LOCAL STRING	nxtarg(INT);
+#define exp	exp_
+LOCAL INT	exp(VOID);
+LOCAL INT	e1(VOID);
+LOCAL INT	e2(VOID);
+LOCAL INT	e3(VOID);
+LOCAL INT	tio(STRING, INT);
+LOCAL INT	ftype(STRING, INT);
+LOCAL INT	fsizep(STRING);
+
+LOCAL CMSG	bramis	= "] missing";
+LOCAL CMSG	argexp	= "argument expected";
+LOCAL CMSG	braexp	= ") expected";
+
+LOCAL INT	ap, ac;
+LOCAL STRING	*av;
+LOCAL STRING	at;
+
+
+INT	test(argn, com)
+	INT		argn;
+	STRING		com[];
+{
         ac = argn; av = com; ap = 1;
         IF eq(com[0],"[")
 	THEN	IF !eq(com[--ac], "]")
-		THEN	failed("test", "] missing");
+		THEN	failed(btest, bramis);
+			/*NOTREACHED*/
 		FI
 	FI
         com[ac] = 0;
@@ -28,34 +44,33 @@
         return(exp()?0:1);
 }
 
-STRING	nxtarg(mt)	{
-
+LOCAL STRING	nxtarg(mt)
+	INT		mt;
+{
 	IF ap >= ac
 	THEN	IF mt
 		THEN	ap++;
                         return(0);
 		FI
-		failed("test", "argument expected");
+		failed(btest, argexp);
+		/*NOTREACHED*/
 	FI
         return(av[ap++]);
 }
 
-exp() {
-        INT p1;
-	STRING	p2;
+LOCAL INT	exp()
+{
+	INT		p1;
 
         p1 = e1();
-        p2 = nxtarg(1);
-	IF eq(p2, "-o")	THEN return(p1 | exp()) FI
-        IF (p2!=0)&&!eq(p2,"]")&&!eq(p2,")")
-	THEN	failed("test", synmsg);
-	FI
+	IF eq(nxtarg(1), "-o") THEN return(p1 | exp()) FI
         ap--;
         return(p1);
 }
 
-e1() {
-        INT p1;
+LOCAL INT	e1()
+{
+	INT		p1;
 
         p1 = e2();
 	IF eq(nxtarg(1), "-a") THEN return(p1 & e1()) FI
@@ -63,7 +78,8 @@
         return(p1);
 }
 
-e2() {
+LOCAL INT	e2()
+{
         IF eq(nxtarg(0), "!")
 	THEN	return(!e3())
 	FI
@@ -71,26 +87,29 @@
         return(e3());
 }
 
-e3() {
-        INT p1;
+LOCAL INT	e3()
+{
+	INT		p1;
 	REG STRING	a;
-	STRING	p2;
-	L_INT	atol();
-        L_INT int1, int2;
+	STRING		p2;
+	LONG		int1, int2;
 
         a=nxtarg(0);
         IF eq(a, "(")
 	THEN	p1 = exp();
-                IF !eq(nxtarg(0), ")") THEN failed("test",") expected") FI
+		IF !eq(nxtarg(0), ")")
+		THEN	failed(btest, braexp)
+			/*NOTREACHED*/
+		FI
                 return(p1);
 	FI
 
         p2 = nxtarg(1);
         ap--;
         IF !eq(p2,"=")&&!eq(p2,"!=")
-	THEN	IF eq(a, "-r") THEN return(tio(nxtarg(0), 4)) FI
-		IF eq(a, "-w") THEN return(tio(nxtarg(0), 2)) FI
-		IF eq(a, "-x") THEN return(tio(nxtarg(0), 1)) FI
+	THEN	IF eq(a, "-r") THEN return(tio(nxtarg(0), R_OK)) FI
+		IF eq(a, "-w") THEN return(tio(nxtarg(0), W_OK)) FI
+		IF eq(a, "-x") THEN return(tio(nxtarg(0), X_OK)) FI
 		IF eq(a, "-d") THEN return(ftype(nxtarg(0), S_IFDIR)) FI
 		IF eq(a, "-c") THEN return(ftype(nxtarg(0),S_IFCHR)) FI
 		IF eq(a, "-b") THEN return(ftype(nxtarg(0), S_IFBLK)) FI
@@ -106,7 +125,7 @@
 				ORF eq(a, "-o")
 			     THEN	ap--;
 					return(isatty(1));
-			ELSE return(isatty(atol(a)));
+			ELSE return(isatty(atoi(a)));
 			FI
 		FI
 		IF eq(a, "-n") THEN return(!eq(nxtarg(0), "")) FI
@@ -121,7 +140,12 @@
 	FI
 	IF eq(p2, "=") THEN return(eq(nxtarg(0), a)) FI
 	IF eq(p2, "!=") THEN return(!eq(nxtarg(0), a)) FI
+	IF eq(a, "-l")
+	THEN	int1 = (LONG) length(p2) - 1;
+		p2 = nxtarg(0);
+	ELSE
         int1 = atol(a);
+	FI
         int2 = atol(nxtarg(0));
 	IF eq(p2, "-eq") THEN return(int1==int2) FI
 	IF eq(p2, "-ne") THEN return(int1!=int2) FI
@@ -131,11 +155,13 @@
 	IF eq(p2, "-le") THEN return(int1<=int2) FI
 
 	bfailed(btest, badop, p2);
+	/*NOTREACHED*/
+	return(0);				/* GCC */
 }
 
-tio(a, f)
-	STRING	a;
-	INT f;
+LOCAL INT	tio(a, f)
+	STRING		a;
+	INT		f;
 {
 	IF access(a, f)==0 
 	THEN	return(1);
@@ -143,11 +169,11 @@
 	FI
 }
 
-ftype(f,field)
-	STRING	f;
-	INT field;
+LOCAL INT	ftype(f,field)
+	STRING		f;
+	INT		field;
 {
-        struct stat statb;
+	STATBUF		statb;
 
 	IF stat(f,&statb)<0 THEN return(0) FI
 	IF (statb.st_mode&field)==field
@@ -156,10 +182,12 @@
 	FI
 }
 
-fsizep(f)
-	STRING	f;
+LOCAL INT	fsizep(f)
+	STRING		f;
 {
-        struct stat statb;
+	STATBUF		statb;
+
 	IF stat(f, &statb) <0 THEN return(0) FI
         return(statb.st_size>0);
 }
+#endif
