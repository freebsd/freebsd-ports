diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ string.c.orig string.c
--- string.c.orig	Fri Jun  4 02:51:02 2004
+++ string.c	Sat Jun 19 18:42:24 2004
@@ -14,19 +14,20 @@
 
 
 STRING	movstr(a,b)
-	REG STRING	a, b;
+	REG CSTRING	a;
+	REG STRING	b;
 {
-	WHILE *b++ = *a++ DONE
+	WHILE (*b++ = *a++)!=0 DONE		/* GCC */
 	return(--b);
 }
 
 INT	any(c,s)
-	REG CHAR	c;
-	STRING		s;
+	REG INT		c;
+	CSTRING		s;
 {
-	REG CHAR d;
+	REG INT		d;
 
-	WHILE d = *s++
+	WHILE (d = *s++)!=0			/* GCC */
 	DO	IF d==c
 		THEN	return(TRUE);
 		FI
@@ -35,7 +36,7 @@
 }
 
 INT	cf(s1, s2)
-	REG STRING s1, s2;
+	REG CSTRING s1, s2;
 {
 	WHILE *s1++ == *s2
 	DO	IF *s2++==0
@@ -46,10 +47,10 @@
 }
 
 INT	length(as)
-	STRING as;
+	CSTRING as;
 {
-	REG STRING s;
+	REG CSTRING s;
 
-	IF s=as THEN WHILE *s++ DONE FI
+	IF (s=as)!=NIL THEN WHILE *s++ DONE FI	/* GCC */
 	return(s-as);
 }
